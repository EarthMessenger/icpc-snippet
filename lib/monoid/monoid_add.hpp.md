---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/internal.hpp
    title: Internal Definition
  - icon: ':heavy_check_mark:'
    path: lib/monoid/monoid_trait.hpp
    title: lib/monoid/monoid_trait.hpp
  _extendedRequiredBy: []
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
    path: verify/ds/point_add_range_sum.test.cpp
    title: verify/ds/point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ lib/internal.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#pragma once\n#include \"lib/internal.hpp\"\n#include \"lib/monoid/monoid_trait.hpp\"\
    \n\nnamespace mono {\n\ntemplate <typename T>\nstruct MonoidAdd : MonoidTrait<T,\
    \ true, ftf<std::plus<T>, const T, const T>>\n{};\n\ntemplate <typename T1, typename\
    \ T2> struct MonoidAdd<std::pair<T1, T2>>\n{\n  using S = std::pair<T1, T2>;\n\
    \  static constexpr S op(const S &x, const S &y)\n  {\n    return S{x.first +\
    \ y.first, x.second + y.second};\n  }\n  static constexpr const S un() { return\
    \ S{T1(), T2()}; }\n  static constexpr S iv(const S &x) { return S{-x.first, -x.second};\
    \ }\n  static constexpr S pw(const S &x, u64 y)\n  {\n    return S{x.first * y,\
    \ x.second * y};\n  }\n  static constexpr bool cm = true;\n};\n\n} // namespace\
    \ mono"
  dependsOn:
  - lib/internal.hpp
  - lib/monoid/monoid_trait.hpp
  isVerificationFile: false
  path: lib/monoid/monoid_add.hpp
  requiredBy: []
  timestamp: '2024-06-15 17:22:49+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/ds/dynamic_tree_vertex_add_path_sum.test.cpp
  - verify/ds/point_add_range_sum.test.cpp
  - verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  - verify/ds/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
documentation_of: lib/monoid/monoid_add.hpp
layout: document
redirect_from:
- /library/lib/monoid/monoid_add.hpp
- /library/lib/monoid/monoid_add.hpp.html
title: lib/monoid/monoid_add.hpp
---
