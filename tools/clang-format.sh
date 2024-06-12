#!/usr/bin/sh
find . -name *.hpp | xargs clang-format -i
