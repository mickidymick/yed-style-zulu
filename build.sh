#!/usr/bin/env bash
gcc -o zulu.so zulu.c $(yed --print-cflags) $(yed --print-ldflags)
