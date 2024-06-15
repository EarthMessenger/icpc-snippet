---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/internal.hpp
    title: Internal Definition
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/ds/lct.hpp
    title: Link Cut Tree
  - icon: ':heavy_check_mark:'
    path: lib/ds/segtree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: lib/monoid/monoid_add.hpp
    title: lib/monoid/monoid_add.hpp
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
  - icon: ':heavy_check_mark:'
    path: verify/ds/point_set_range_composite.test.cpp
    title: verify/ds/point_set_range_composite.test.cpp
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
  code: "#pragma once\n\n#include \"lib/internal.hpp\"\n\n// Transfer functor into\
    \ function to avoid errors under c++20 above c++11.\ntemplate <typename Functor,\
    \ class... Args> auto ftf(Args &&...args)\n{\n  static Functor f;\n  return f(std::forward<Args>(args)...);\n\
    }\n\n// default unit function\ntemplate <typename T> constexpr const T dunf()\
    \ { return T(); }\n\n// default inverse function\ntemplate <typename T, const\
    \ T (*U)() = dunf<T>,\n          T (*D)(const T &&, const T &&) = ftf<std::divides<T>,\
    \ T, T>>\nconstexpr T divf(const T &&x)\n{\n  return D(std::forward<const T>(U()),\
    \ std::forward<const T>(x));\n}\n\n// default power function\ntemplate <typename\
    \ T, T (*O)(const T &&, const T &&), const T (*U)() = dunf<T>>\nconstexpr T dpwf(const\
    \ T &&x, u64 &&y)\n{\n  T r = U(), v = x;\n  for (; y; y /= 2) {\n    if (y &\
    \ 1) r = O(std::forward<const T>(r), std::forward<const T>(v));\n    v = O(std::forward<const\
    \ T>(v), std::forward<const T>(v));\n  }\n  return r;\n}\n\n// const integer function\n\
    template <i64 V> constexpr i64 cintf() { return V; }\n\n// default act funcion\
    \ (similar to std::invoke)\ntemplate <typename A, typename B> B dactf(const A\
    \ &&a, const B &&b, u64 &&len)\n{\n  return a * b;\n}\n\n//////////////////////////////////////////////////////////////////////////\n\
    \nnamespace mono {\n\n#if __cplusplus >= 202000U\n\ntemplate <typename _S, bool\
    \ C = false, auto O = std::multiplies(),\n          auto E = dunf<_S>, auto P\
    \ = dpwf<_S, O, E>, auto I = divf<_S>>\n\n#else\n\ntemplate <typename _S, bool\
    \ C = false,\n          _S (*O)(const _S &&, const _S &&) =\n              ftf<std::multiplies<_S>,\
    \ const _S, const _S>,\n          const _S (*E)() = dunf<_S>,\n          _S (*P)(const\
    \ _S &&, u64 &&) = dpwf<_S, O, E>,\n          _S (*I)(const _S &&) = divf<_S>>\n\
    #endif\nstruct GroupTrait\n{\n  using S = _S;\n  using MS = GroupTrait;\n  static\
    \ constexpr S op(const S &x, const S &y)\n  {\n    return O(std::forward<const\
    \ S>(x), std::forward<const S>(y));\n  }\n  static constexpr const S un() { return\
    \ E(); }\n  static constexpr S iv(const S &x) { return I(std::forward<const S>(x));\
    \ }\n  static constexpr S pw(const S &x, u64 y)\n  {\n    return P(std::forward<const\
    \ S>(x), std::forward<u64>(y));\n  }\n  static constexpr bool cm = C;\n};\n\n\
    #if __cplusplus >= 202000U\n\ntemplate <typename _S, bool C = false, auto O =\
    \ std::multiplies(),\n          auto E = dunf<_S>, auto P = dpwf<_S, O, E>>\n\n\
    #else\n\ntemplate <typename _S, bool C = false,\n          _S (*O)(const _S &&,\
    \ const _S &&) =\n              ftf<std::multiplies<_S>, const _S, const _S>,\n\
    \          const _S (*E)() = dunf<_S>,\n          _S (*P)(const _S &&, u64 &&)\
    \ = dpwf<_S, O, E>>\n#endif\nstruct MonoidTrait: GroupTrait<_S, C, O, E, P, nullptr>\n\
    {\n  using S = _S;\n  using MS = MonoidTrait;\n};\n\n#if __cplusplus >= 202000U\n\
    template <typename _MA, typename _MS,\n          auto _AP = dactf<typename _MA::S,\
    \ typename _MS::S>>\n#else\ntemplate <typename _MA, typename _MS,\n          typename\
    \ _MS::S (*_AP)(const typename _MA::S &&,\n                                 const\
    \ typename _MS::S &&, u64 &&) =\n              dactf<typename _MA::S, typename\
    \ _MS::S>>\n#endif\nstruct ActedMonoidTrait : _MS\n{\n  using MA = _MA;\n  using\
    \ MS = _MS;\n  using A = typename MA::S;\n  using S = typename MS::S;\n  static\
    \ constexpr S act(const A &a, const S &s, u64 len)\n  {\n    return _AP(std::forward<const\
    \ A>(a), std::forward<const S>(s),\n               std::forward<u64>(len));\n\
    \  }\n};\n\ntemplate <typename _M, bool _cm = _M::cm> struct BidirMonoidTrait\n\
    {};\n\ntemplate <typename _M> struct BidirMonoidTrait<_M, true>\n{\n  using MS\
    \ = typename _M::MS;\n  using BS = typename MS::S;\n  using S = BS;\n  static\
    \ constexpr S ts(const S &x) { return x; }\n  static constexpr S op(const S &x,\
    \ const S &y) { return MS::op(x, y); }\n  static constexpr const S un() { return\
    \ MS::un(); }\n  static constexpr S iv(const S &x) { return MS::iv(x); }\n  static\
    \ constexpr S pw(const S &x, u64 y) { return MS::pw(x, y); }\n  static constexpr\
    \ bool cm = true;\n};\n\ntemplate <typename _M> struct BidirMonoidTrait<_M, false>\n\
    {\n  using MS = typename _M::MS;\n  using BS = typename MS::S;\n  using S = std::pair<BS,\
    \ BS>;\n  static constexpr S ts(const S &x) { return S(x.second, x.first); }\n\
    \  static constexpr S op(const S &x, const S &y)\n  {\n    return S{MS::op(x.first,\
    \ y.first), MS::op(y.second, x.second)};\n  }\n  static constexpr const S un()\
    \ { return S{MS::un(), MS::un()}; }\n  static constexpr S iv(const S &x)\n  {\n\
    \    return S{MS::iv(x.first), MS::iv(x.second)};\n  }\n  static constexpr S pw(const\
    \ S &x, u64 y)\n  {\n    return S{MS::pw(x.first, y), MS::pw(x.second, y)};\n\
    \  }\n  static constexpr bool cm = false;\n};\n\ntemplate <typename _M, bool _cm\
    \ = _M::cm> struct BidirActedMonoidTrait\n{};\ntemplate <typename _M>\nstruct\
    \ BidirActedMonoidTrait<_M, true> : BidirMonoidTrait<_M, true>\n{\n  using MA\
    \ = typename _M::MA;\n  using A = typename MA::S;\n  using MS = typename BidirMonoidTrait<_M,\
    \ true>::MS;\n  using BS = typename BidirMonoidTrait<_M, true>::BS;\n  using S\
    \ = typename BidirMonoidTrait<_M, true>::S;\n  static constexpr S act(const A\
    \ &a, const S &s, u64 len)\n  {\n    return _M::act(a, s, len);\n  }\n};\ntemplate\
    \ <typename _M>\nstruct BidirActedMonoidTrait<_M, false> : BidirMonoidTrait<_M,\
    \ false>\n{\n  using MA = typename _M::MA;\n  using A = typename MA::S;\n  using\
    \ MS = typename BidirMonoidTrait<_M, false>::MS;\n  using BS = typename BidirMonoidTrait<_M,\
    \ false>::BS;\n  using S = typename BidirMonoidTrait<_M, false>::S;\n  static\
    \ constexpr S act(const A &a, const S &s, u64 len)\n  {\n    return S{_M::act(a,\
    \ s.first, len), _M::act(a, s.second, len)};\n  }\n};\n\n} // namespace mono"
  dependsOn:
  - lib/internal.hpp
  isVerificationFile: false
  path: lib/monoid/monoid_trait.hpp
  requiredBy:
  - lib/ds/lct.hpp
  - lib/ds/segtree.hpp
  - lib/monoid/monoid_add.hpp
  timestamp: '2024-06-15 17:22:49+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/ds/dynamic_tree_vertex_add_path_sum.test.cpp
  - verify/ds/point_add_range_sum.test.cpp
  - verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  - verify/ds/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
  - verify/ds/point_set_range_composite.test.cpp
documentation_of: lib/monoid/monoid_trait.hpp
layout: document
redirect_from:
- /library/lib/monoid/monoid_trait.hpp
- /library/lib/monoid/monoid_trait.hpp.html
title: lib/monoid/monoid_trait.hpp
---
