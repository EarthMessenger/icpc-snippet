---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/internal.hpp
    title: Internal Definition
  _extendedRequiredBy:
  - icon: ':x:'
    path: lib/ds/segtree.hpp
    title: Segment Tree
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/ds/point_add_range_sum.test.cpp
    title: verify/ds/point_add_range_sum.test.cpp
  - icon: ':x:'
    path: verify/ds/point_set_range_composite.test.cpp
    title: verify/ds/point_set_range_composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
  code: "#pragma once\n#include \"lib/internal.hpp\"\n#include <functional>\n\nnamespace\
    \ mono {\n\n// Transfer functor into function to avoid errors under c++20.\ntemplate\
    \ <typename Functor, class... Args> auto ftf(const Args &&...args)\n{\n  static\
    \ Functor f;\n  return f(std::forward<const Args>(args)...);\n}\n// default unit\
    \ function\ntemplate <typename T> constexpr const T dunf() { return T(); }\n//\
    \ default inverse function\ntemplate <typename T, const T (*U)() = dunf<T>,\n\
    \          T (*D)(const T &&, const T &&) = ftf<std::divides<T>, T, T>>\nconstexpr\
    \ T divf(const T &&x)\n{\n  return D(std::forward<const T>(U()), std::forward<const\
    \ T>(x));\n}\n// default power function\ntemplate <typename T, T (*O)(const T\
    \ &&, const T &&), const T (*U)() = dunf<T>>\nconstexpr T dpwf(T &&x, u64 y)\n\
    {\n  T r = U();\n  for (; y; y /= 2) {\n    if (y & 1) r = O(std::forward<const\
    \ T>(r), std::forward<const T>(x));\n    x = O(std::forward<const T>(x), std::forward<const\
    \ T>(x));\n  }\n  return r;\n}\n// const integer function\ntemplate <i64 V> constexpr\
    \ i64 cintf() { return V; }\n\n#if __cplusplus >= 202000U\n\ntemplate <typename\
    \ T, auto O = std::multiplies(), auto E = dunf<T>,\n          auto P = dpwf<T,\
    \ O, E>, auto I = nullptr, bool C = false>\n\n#else\n\ntemplate <typename T,\n\
    \          T (*O)(const T &&, const T &&) = ftf<std::multiplies<T>, T, T>,\n \
    \         const T (*E)() = dunf<T>, T (*P)(T &&, u64) = dpwf<T, O, E>,\n     \
    \     T (*I)(const T &&) = nullptr, bool C = false>\n#endif\nstruct GroupTrait\n\
    {\n  using S = T;\n  static constexpr S op(const S &x, const S &y)\n  {\n    return\
    \ O(std::forward<const S>(x), std::forward<const S>(y));\n  }\n  static constexpr\
    \ const S un() { return E(); }\n  static constexpr S iv(const S &x) { return I(std::forward<const\
    \ S>(x)); }\n  static constexpr S pw(S x, u64 y) { return P(std::forward<S>(x),\
    \ y); }\n  static constexpr bool cm = C;\n};\n\ntemplate <typename T> struct MonoidAdd\
    \ : GroupTrait<T, ftf<std::plus<T>, T, T>>\n{};\n\ntemplate <typename T1, typename\
    \ T2> struct MonoidAdd<std::pair<T1, T2>>\n{\n  using S = std::pair<T1, T2>;\n\
    \  static constexpr S op(const S &x, const S &y)\n  {\n    return S{x.first +\
    \ y.first, x.second + y.second};\n  }\n  static constexpr const S un() { return\
    \ S{T1(), T2()}; }\n  static constexpr S iv(const S &x) { return S{-x.first, -x.second};\
    \ }\n  static constexpr S pw(S &&x, u64 y) { return S{x.first * y, x.second *\
    \ y}; }\n  static constexpr bool cm = false;\n};\n\ntemplate <typename T, auto\
    \ None = cintf<-1ll>> struct MonoidAssign\n{\n  using S = T;\n  static constexpr\
    \ S s_none = S(None);\n  static constexpr S op(const S &x, const S &y) { return\
    \ y == s_none ? x : y; }\n  static constexpr const S un() { return s_none; }\n\
    \  static constexpr bool cm = false;\n};\n// default act funcion (similar to std::invoke)\n\
    template <typename A, typename B> B dactf(const A &&a, const B &&b, u64 len)\n\
    {\n  return a(std::forward<const B>(b), len);\n}\n\n#if __cplusplus >= 202000U\n\
    template <typename _GS, typename _GA, auto _AP = dactf<_GA, _GS>>\n#else\ntemplate\
    \ <typename _GS, typename _GA,\n          _GS (*_AP)(const _GS &, const _GA &,\
    \ u64) = dactf<_GA, _GS>>\n#endif\nstruct ActedGroupTrait\n{\n  using GS = _GS;\n\
    \  using GA = _GA;\n  using S = typename GS::S;\n  using A = typename GA::A;\n\
    \  static constexpr S act(const A &a, const S &s, u64 len)\n  {\n    return _AP(std::forward<const\
    \ A>(a), std::forward<const S>(s), len);\n  }\n};\n\n} // namespace mono"
  dependsOn:
  - lib/internal.hpp
  isVerificationFile: false
  path: lib/misc/monoid.hpp
  requiredBy:
  - lib/ds/segtree.hpp
  timestamp: '2024-06-14 11:47:20+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/ds/point_add_range_sum.test.cpp
  - verify/ds/point_set_range_composite.test.cpp
documentation_of: lib/misc/monoid.hpp
layout: document
redirect_from:
- /library/lib/misc/monoid.hpp
- /library/lib/misc/monoid.hpp.html
title: lib/misc/monoid.hpp
---
