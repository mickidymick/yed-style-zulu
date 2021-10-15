#include <yed/plugin.h>

#define MAYBE_CONVERT(rgb) (tc ? (rgb) : rgb_to_256(rgb))

PACKABLE_STYLE(first) {
    yed_style s;
    int       tc,
              attr_kind;

    YED_PLUG_VERSION_CHECK();

    tc        = !!yed_get_var("truecolor");
    attr_kind = tc ? ATTR_RGB : ATTR_256;

    memset(&s, 0, sizeof(s));

    s.active.flags        = attr_kind;
    s.active.fg           = MAYBE_CONVERT(RGB_32_hex(A5ACAF));
    s.active.bg           = MAYBE_CONVERT(RGB_32_hex(172833));
    s.active_border       = s.active;
    s.active_gutter       = s.active;

    s.inactive.flags      = attr_kind;
    s.inactive.fg         = MAYBE_CONVERT(RGB_32_hex(A5ACAF));
    s.inactive.bg         = MAYBE_CONVERT(RGB_32_hex(0D161C));
    s.inactive_border     = s.inactive;
    s.inactive_gutter     = s.inactive;

    s.cursor_line.flags    = attr_kind;
    s.cursor_line.bg      = MAYBE_CONVERT(RGB_32_hex(34454B));

    s.selection.flags     = attr_kind;
    s.selection.fg        = MAYBE_CONVERT(RGB_32_hex(003439));
    s.selection.bg        = MAYBE_CONVERT(RGB_32_hex(556C77));

    s.search.flags        = attr_kind;
    s.search.fg           = MAYBE_CONVERT(RGB_32_hex(172833));
    s.search.bg           = MAYBE_CONVERT(RGB_32_hex(00CFA9));

    s.search_cursor.flags = attr_kind;
    s.search_cursor.fg    = MAYBE_CONVERT(RGB_32_hex(172833));
    s.search_cursor.bg    = MAYBE_CONVERT(RGB_32_hex(F0428B));

    s.attention.flags     = attr_kind | ATTR_BOLD;
    s.attention.fg        = MAYBE_CONVERT(RGB_32_hex(F0428B));

    s.associate.flags     = attr_kind | ATTR_BOLD;
    s.associate.fg        = MAYBE_CONVERT( RGB_32_hex(FF6600));
    s.associate.bg        = MAYBE_CONVERT( RGB_32_hex(34454B));

    s.status_line.flags   = attr_kind | ATTR_BOLD;
    s.status_line.fg      = MAYBE_CONVERT(RGB_32_hex(003439));
    s.status_line.bg      = MAYBE_CONVERT(RGB_32_hex(668591));

    s.command_line        = s.active;

    s.code_comment.flags  = attr_kind | ATTR_BOLD;
    s.code_comment.fg     = MAYBE_CONVERT(RGB_32_hex(555760));

    s.code_keyword.flags  = attr_kind | ATTR_BOLD;
    s.code_keyword.fg     = MAYBE_CONVERT(RGB_32_hex(9D57B3));

    s.code_control_flow.flags = attr_kind;
    s.code_control_flow.fg    = MAYBE_CONVERT(RGB_32_hex(ED8E29));

    s.code_typename.flags     = attr_kind | ATTR_BOLD;
    s.code_typename.fg        = MAYBE_CONVERT(RGB_32_hex(3DBAAA));

    s.code_preprocessor.flags = attr_kind | ATTR_BOLD;
    s.code_preprocessor.fg    = MAYBE_CONVERT(RGB_32_hex(CFCFCF));

    s.code_fn_call.flags      = attr_kind | ATTR_BOLD;
    s.code_fn_call.fg         = MAYBE_CONVERT(RGB_32_hex(F0428B));

    s.code_number.flags       = attr_kind;
    s.code_number.fg          = MAYBE_CONVERT(RGB_32_hex(FFFF80));

    s.code_constant           = s.code_preprocessor;

    s.code_string.flags       = attr_kind;
    s.code_string.fg          = MAYBE_CONVERT(RGB_32_hex(59B582));

    s.code_character      = s.code_string;

    yed_plugin_set_style(self, "zulu", &s);

    return 0;
}
