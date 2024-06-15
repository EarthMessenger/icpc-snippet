---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/ds/depque.hpp
    title: Double Ended Priority Queue
  - icon: ':warning:'
    path: lib/ds/dynsegtree.hpp
    title: lib/ds/dynsegtree.hpp
  - icon: ':heavy_check_mark:'
    path: lib/ds/lazysegtree.hpp
    title: lib/ds/lazysegtree.hpp
  - icon: ':heavy_check_mark:'
    path: lib/ds/lct.hpp
    title: Link Cut Tree
  - icon: ':heavy_check_mark:'
    path: lib/ds/rbst.hpp
    title: Random Binary Search Tree
  - icon: ':heavy_check_mark:'
    path: lib/ds/segtree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: lib/ds/splay.hpp
    title: Splay Tree
  - icon: ':warning:'
    path: lib/graph/maxflow.hpp
    title: Max Flow
  - icon: ':heavy_check_mark:'
    path: lib/graph/scc.hpp
    title: Strongly Connected Components
  - icon: ':heavy_check_mark:'
    path: lib/math/convolution.hpp
    title: Polynomial Convolution
  - icon: ':warning:'
    path: lib/math/dynamic_modint.hpp
    title: Dynamic Modint
  - icon: ':warning:'
    path: lib/math/lucas.hpp
    title: Lucas Theorem
  - icon: ':heavy_check_mark:'
    path: lib/math/static_modint.hpp
    title: Static Modint
  - icon: ':warning:'
    path: lib/math/utility.hpp
    title: Usual Math Algorithm
  - icon: ':heavy_check_mark:'
    path: lib/misc/bitop.hpp
    title: Bit Manipulation
  - icon: ':heavy_check_mark:'
    path: lib/monoid/monoid_add.hpp
    title: lib/monoid/monoid_add.hpp
  - icon: ':warning:'
    path: lib/monoid/monoid_affine.hpp
    title: lib/monoid/monoid_affine.hpp
  - icon: ':heavy_check_mark:'
    path: lib/monoid/monoid_linear_function.hpp
    title: lib/monoid/monoid_linear_function.hpp
  - icon: ':heavy_check_mark:'
    path: lib/monoid/monoid_trait.hpp
    title: lib/monoid/monoid_trait.hpp
  - icon: ':warning:'
    path: lib/str/kmp.hpp
    title: lib/str/kmp.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/ds/area_of_union_of_rectangles.test.cpp
    title: verify/ds/area_of_union_of_rectangles.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/ds/double_ended_priority_queue.test.cpp
    title: verify/ds/double_ended_priority_queue.test.cpp
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
    path: verify/ds/point_add_range_sum.test.cpp
    title: verify/ds/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/ds/point_set_range_composite.test.cpp
    title: verify/ds/point_set_range_composite.test.cpp
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
  - icon: ':heavy_check_mark:'
    path: verify/str/longest_common_substring.test.cpp
    title: verify/str/longest_common_substring.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/str/number_of_substrings.test.cpp
    title: verify/str/number_of_substrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/str/suffixarray.test.cpp
    title: verify/str/suffixarray.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Internal Definition
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ lib/internal.hpp: line 4: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Internal Definition\n */\n#pragma once\n#include <cmath>\n\
    #include <tuple>\n#include <vector>\n#include <utility>\n#include <cstring>\n\
    #include <iostream>\n#include <algorithm>\n#include <functional>\n\nusing i32\
    \ = int;\nusing i64 = long long;\nusing i128 = __int128_t;\nusing u32 = unsigned\
    \ int;\nusing u64 = unsigned long long;\nusing u128 = __uint128_t;\n\ntemplate\
    \ <typename T> using vec = std::vector<T>;\nusing pii = std::pair<int, int>;"
  dependsOn: []
  isVerificationFile: false
  path: lib/internal.hpp
  requiredBy:
  - lib/misc/bitop.hpp
  - lib/ds/rbst.hpp
  - lib/ds/depque.hpp
  - lib/ds/dynsegtree.hpp
  - lib/ds/lazysegtree.hpp
  - lib/ds/lct.hpp
  - lib/ds/splay.hpp
  - lib/ds/segtree.hpp
  - lib/graph/maxflow.hpp
  - lib/graph/scc.hpp
  - lib/math/utility.hpp
  - lib/math/convolution.hpp
  - lib/math/dynamic_modint.hpp
  - lib/math/lucas.hpp
  - lib/math/static_modint.hpp
  - lib/monoid/monoid_affine.hpp
  - lib/monoid/monoid_trait.hpp
  - lib/monoid/monoid_add.hpp
  - lib/monoid/monoid_linear_function.hpp
  - lib/str/kmp.hpp
  timestamp: '2024-06-14 09:23:51+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/ds/dynamic_tree_vertex_add_path_sum.test.cpp
  - verify/ds/point_add_range_sum.test.cpp
  - verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  - verify/ds/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
  - verify/ds/double_ended_priority_queue.test.cpp
  - verify/ds/area_of_union_of_rectangles.test.cpp
  - verify/ds/static_range_inversions_query.test.cpp
  - verify/ds/point_set_range_composite.test.cpp
  - verify/graph/scc.test.cpp
  - verify/math/convolution.test.cpp
  - verify/math/bitwise_and_convolution.test.cpp
  - verify/math/bitwise_xor_convolution.test.cpp
  - verify/math/subset_convolution.test.cpp
  - verify/str/number_of_substrings.test.cpp
  - verify/str/suffixarray.test.cpp
  - verify/str/longest_common_substring.test.cpp
documentation_of: lib/internal.hpp
layout: document
redirect_from:
- /library/lib/internal.hpp
- /library/lib/internal.hpp.html
title: Internal Definition
---
