---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/internal.hpp
    title: lib/internal.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/math/convolution.test.cpp
    title: verify/math/convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/internal.hpp\"\n#include <algorithm>\n#include <cmath>\n\
    #include <cstring>\n#include <iostream>\n#include <tuple>\n#include <utility>\n\
    #include <vector>\n\nusing i32 = int;\nusing i64 = long long;\nusing i128 = __int128_t;\n\
    using u32 = unsigned int;\nusing u64 = unsigned long long;\nusing u128 = __uint128_t;\n\
    \ntemplate <typename T> using vec = std::vector<T>;\nusing pii = std::pair<int,\
    \ int>;\n#line 3 \"lib/misc/bitop.hpp\"\n\nint clz(u64 x) { return __builtin_clzll(x);\
    \ }\nint ctz(u64 x) { return __builtin_ctzll(x); }\n// floor(log2(x))\nint lg2(u64\
    \ x) { return 63 ^ clz(x); }\n// bit width\nint btw(u64 x) { return lg2(x) + 1;\
    \ }\n// bit ceil\nu64 btc(u64 x) { return (x <= 1 ? 1 : 1ull << btw(x - 1)); }\n\
    // bit floor\nu64 btf(u64 x) { return 1ull << lg2(x); }\n// popcount\n__attribute__((target(\"\
    popcnt\"))) int ppc(u64 x)\n{\n  return __builtin_popcountll(x);\n}\n"
  code: "#pragma once\n#include \"lib/internal.hpp\"\n\nint clz(u64 x) { return __builtin_clzll(x);\
    \ }\nint ctz(u64 x) { return __builtin_ctzll(x); }\n// floor(log2(x))\nint lg2(u64\
    \ x) { return 63 ^ clz(x); }\n// bit width\nint btw(u64 x) { return lg2(x) + 1;\
    \ }\n// bit ceil\nu64 btc(u64 x) { return (x <= 1 ? 1 : 1ull << btw(x - 1)); }\n\
    // bit floor\nu64 btf(u64 x) { return 1ull << lg2(x); }\n// popcount\n__attribute__((target(\"\
    popcnt\"))) int ppc(u64 x)\n{\n  return __builtin_popcountll(x);\n}"
  dependsOn:
  - lib/internal.hpp
  isVerificationFile: false
  path: lib/misc/bitop.hpp
  requiredBy: []
  timestamp: '2024-06-12 11:51:09+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/math/convolution.test.cpp
documentation_of: lib/misc/bitop.hpp
layout: document
redirect_from:
- /library/lib/misc/bitop.hpp
- /library/lib/misc/bitop.hpp.html
title: lib/misc/bitop.hpp
---
