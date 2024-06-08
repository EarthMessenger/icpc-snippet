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
  bundledCode: '#line 2 "lib/internal.hpp"

    #include <cmath>

    #include <tuple>

    #include <vector>

    #include <utility>

    #include <cstring>

    #include <iostream>

    #include <algorithm>


    using i32 = int;

    using i64 = long long;

    using i128 = __int128_t;

    using u32 = unsigned int;

    using u64 = unsigned long long;

    using u128 = __uint128_t;


    template<typename T> using vec = std::vector<T>;

    using pii = std::pair<int, int>;

    #line 3 "lib/misc/bitop.hpp"


    int clz(u64 x) { return __builtin_clzll(x); }

    int ctz(u64 x) { return __builtin_ctzll(x); }

    // floor(log2(x))

    int lg2(u64 x) { return 63 ^ clz(x); }

    // bit width

    int btw(u64 x) { return lg2(x) + 1; }

    // bit ceil

    u64 btc(u64 x) { return (x <= 1 ? 1: 1ull << btw(x - 1)); }

    // bit floor

    u64 btf(u64 x) { return 1ull << lg2(x); }

    // popcount

    __attribute__((target("popcnt")))

    int ppc(u64 x) { return __builtin_popcountll(x); }

    '
  code: '#pragma once

    #include "lib/internal.hpp"


    int clz(u64 x) { return __builtin_clzll(x); }

    int ctz(u64 x) { return __builtin_ctzll(x); }

    // floor(log2(x))

    int lg2(u64 x) { return 63 ^ clz(x); }

    // bit width

    int btw(u64 x) { return lg2(x) + 1; }

    // bit ceil

    u64 btc(u64 x) { return (x <= 1 ? 1: 1ull << btw(x - 1)); }

    // bit floor

    u64 btf(u64 x) { return 1ull << lg2(x); }

    // popcount

    __attribute__((target("popcnt")))

    int ppc(u64 x) { return __builtin_popcountll(x); }'
  dependsOn:
  - lib/internal.hpp
  isVerificationFile: false
  path: lib/misc/bitop.hpp
  requiredBy: []
  timestamp: '2024-06-08 15:08:56+08:00'
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
