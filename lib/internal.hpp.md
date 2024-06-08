---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: lib/ds/depque.hpp
    title: double ended priority queue
  - icon: ':heavy_check_mark:'
    path: lib/ds/lct.hpp
    title: lib/ds/lct.hpp
  - icon: ':heavy_check_mark:'
    path: lib/ds/rbst.hpp
    title: lib/ds/rbst.hpp
  - icon: ':heavy_check_mark:'
    path: lib/ds/splay.hpp
    title: lib/ds/splay.hpp
  - icon: ':warning:'
    path: lib/graph/maxflow.hpp
    title: lib/graph/maxflow.hpp
  - icon: ':heavy_check_mark:'
    path: lib/graph/scc.hpp
    title: lib/graph/scc.hpp
  - icon: ':heavy_check_mark:'
    path: lib/math/convolution.hpp
    title: lib/math/convolution.hpp
  - icon: ':warning:'
    path: lib/math/dynamic_modint.hpp
    title: lib/math/dynamic_modint.hpp
  - icon: ':warning:'
    path: lib/math/fast_gcd.hpp
    title: lib/math/fast_gcd.hpp
  - icon: ':warning:'
    path: lib/math/prime.hpp
    title: lib/math/prime.hpp
  - icon: ':heavy_check_mark:'
    path: lib/math/static_modint.hpp
    title: lib/math/static_modint.hpp
  - icon: ':heavy_check_mark:'
    path: lib/misc/bitop.hpp
    title: lib/misc/bitop.hpp
  - icon: ':warning:'
    path: lib/str/kmp.hpp
    title: lib/str/kmp.hpp
  - icon: ':warning:'
    path: verify/ds/double_ended_priority_queue.FIXME.cpp
    title: verify/ds/double_ended_priority_queue.FIXME.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/ds/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
    title: verify/ds/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp
    title: verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/ds/dynamic_tree_vertex_add_path_sum.test.cpp
    title: verify/ds/dynamic_tree_vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/ds/static_range_inversions_query.test.cpp
    title: verify/ds/static_range_inversions_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/scc.test.cpp
    title: verify/graph/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/math/bitwise_and_convolution.test.cpp
    title: verify/math/bitwise_and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/math/bitwise_xor_convolution.test.cpp
    title: verify/math/bitwise_xor_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/math/convolution.test.cpp
    title: verify/math/convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/math/subset_convolution.test.cpp
    title: verify/math/subset_convolution.test.cpp
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

    '
  code: '#pragma once

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

    using pii = std::pair<int, int>;'
  dependsOn: []
  isVerificationFile: false
  path: lib/internal.hpp
  requiredBy:
  - lib/misc/bitop.hpp
  - lib/ds/rbst.hpp
  - lib/ds/depque.hpp
  - lib/ds/lct.hpp
  - lib/ds/splay.hpp
  - lib/graph/maxflow.hpp
  - lib/graph/scc.hpp
  - lib/math/convolution.hpp
  - lib/math/dynamic_modint.hpp
  - lib/math/fast_gcd.hpp
  - lib/math/static_modint.hpp
  - lib/math/prime.hpp
  - lib/str/kmp.hpp
  - verify/ds/double_ended_priority_queue.FIXME.cpp
  timestamp: '2024-06-08 15:08:56+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/ds/dynamic_tree_vertex_add_path_sum.test.cpp
  - verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  - verify/ds/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
  - verify/ds/static_range_inversions_query.test.cpp
  - verify/graph/scc.test.cpp
  - verify/math/convolution.test.cpp
  - verify/math/bitwise_and_convolution.test.cpp
  - verify/math/bitwise_xor_convolution.test.cpp
  - verify/math/subset_convolution.test.cpp
documentation_of: lib/internal.hpp
layout: document
redirect_from:
- /library/lib/internal.hpp
- /library/lib/internal.hpp.html
title: lib/internal.hpp
---
