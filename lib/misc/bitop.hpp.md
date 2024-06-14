---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/internal.hpp
    title: Internal Definition
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/ds/lazysegtree.hpp
    title: lib/ds/lazysegtree.hpp
  - icon: ':heavy_check_mark:'
    path: lib/ds/segtree.hpp
    title: Segment Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/ds/area_of_union_of_rectangles.test.cpp
    title: verify/ds/area_of_union_of_rectangles.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/ds/point_add_range_sum.test.cpp
    title: verify/ds/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/ds/point_set_range_composite.test.cpp
    title: verify/ds/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/math/convolution.test.cpp
    title: verify/math/convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Bit Manipulation
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ lib/misc/bitop.hpp: line 4: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Bit Manipulation\n */\n#pragma once\n#include \"lib/internal.hpp\"\
    \n\nint clz(u64 x) { return __builtin_clzll(x); }\nint ctz(u64 x) { return __builtin_ctzll(x);\
    \ }\n// floor(log2(x))\nint lg2(u64 x) { return 63 ^ clz(x); }\n// bit width\n\
    int btw(u64 x) { return lg2(x) + 1; }\n// bit ceil\nu64 btc(u64 x) { return (x\
    \ <= 1 ? 1 : 1ull << btw(x - 1)); }\n// bit floor\nu64 btf(u64 x) { return 1ull\
    \ << lg2(x); }\n// popcount\n__attribute__((target(\"popcnt\"))) int ppc(u64 x)\n\
    {\n  return __builtin_popcountll(x);\n}"
  dependsOn:
  - lib/internal.hpp
  isVerificationFile: false
  path: lib/misc/bitop.hpp
  requiredBy:
  - lib/ds/lazysegtree.hpp
  - lib/ds/segtree.hpp
  timestamp: '2024-06-14 09:23:51+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/ds/point_add_range_sum.test.cpp
  - verify/ds/area_of_union_of_rectangles.test.cpp
  - verify/ds/point_set_range_composite.test.cpp
  - verify/math/convolution.test.cpp
documentation_of: lib/misc/bitop.hpp
layout: document
redirect_from:
- /library/lib/misc/bitop.hpp
- /library/lib/misc/bitop.hpp.html
title: Bit Manipulation
---
