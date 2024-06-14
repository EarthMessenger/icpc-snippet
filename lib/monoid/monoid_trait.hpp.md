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
  - icon: ':x:'
    path: lib/monoid/monoid_add.hpp
    title: lib/monoid/monoid_add.hpp
  - icon: ':warning:'
    path: lib/monoid/monoid_linear_function.hpp
    title: lib/monoid/monoid_linear_function.hpp
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
  code: "#pragma once\n\n#include \"lib/internal.hpp\"\n\n// Transfer functor into\
    \ function to avoid errors under c++20.\ntemplate <typename Functor, class...\
    \ Args> auto ftf(Args &&...args)\n{\n  static Functor f;\n  return f(std::forward<Args>(args)...);\n\
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
    \ &&a, const B &&b, u64 &&len)\n{\n  return a(std::forward<const B>(b), std::forward<u64>(len));\n\
    }\n\n//////////////////////////////////////////////////////////////////////////\n\
    \nnamespace mono {\n\n#if __cplusplus >= 202000U\n\ntemplate <typename T, auto\
    \ O = std::multiplies(), auto E = dunf<T>,\n          auto P = dpwf<T, O, E>,\
    \ auto I = nullptr, bool C = false>\n\n#else\n\ntemplate <typename T,\n      \
    \    T (*O)(const T &&, const T &&) =\n              ftf<std::multiplies<T>, const\
    \ T, const T>,\n          const T (*E)() = dunf<T>, T (*P)(const T &&, u64 &&)\
    \ = dpwf<T, O, E>,\n          T (*I)(const T &&) = nullptr, bool C = false>\n\
    #endif\nstruct MonoidTrait\n{\n  using S = T;\n  static constexpr S op(const S\
    \ &x, const S &y)\n  {\n    return O(std::forward<const S>(x), std::forward<const\
    \ S>(y));\n  }\n  static constexpr const S un() { return E(); }\n  static constexpr\
    \ S iv(const S &x) { return I(std::forward<const S>(x)); }\n  static constexpr\
    \ S pw(const S &x, u64 y)\n  {\n    return P(std::forward<const S>(x), std::forward<u64>(y));\n\
    \  }\n  static constexpr bool cm = C;\n};\n\n#if __cplusplus >= 202000U\ntemplate\
    \ <typename _MA, typename _MS, auto _AP = dactf<_MA, _MS>>\n#else\ntemplate <typename\
    \ _MA, typename _MS,\n          typename _MS::S (*_AP)(const typename _MA::S &&,\n\
    \                                 const typename _MS::S &&, u64 &&) =\n      \
    \        dactf<_MA, _MS>>\n#endif\nstruct ActedMonoidTrait\n{\n  using MA = _MA;\n\
    \  using MS = _MS;\n  using A = typename MA::S;\n  using S = typename MS::S;\n\
    \  static constexpr S act(const A &a, const S &s, u64 len)\n  {\n    return _AP(std::forward<const\
    \ A>(a), std::forward<const S>(s),\n               std::forward<u64>(len));\n\
    \  }\n};\n\ntemplate <typename _M, bool _cm = _M::cm> struct BidirMonoidTrait\
    \ {};\n\ntemplate <typename _M> struct BidirMonoidTrait<_M, true>\n{\n  using\
    \ M = _M;\n  using BS = typename M::S;\n  using S = BS;\n  static constexpr S\
    \ ts(const S &x) { return x; }\n  static constexpr S op(const S &x, const S &y)\n\
    \  {\n    return M::op(std::forward<const S>(x), std::forward<const S>(y));\n\
    \  }\n  static constexpr const S un() { return M::un(); }\n  static constexpr\
    \ S iv(const S &x)\n  {\n    return M::iv(std::forward<const S>(x));\n  }\n  static\
    \ constexpr S pw(const S &x, u64 y)\n  {\n    return M::pw(std::forward<const\
    \ S>(x), std::forward<u64>(y));\n  }\n  static constexpr bool cm = true;\n};\n\
    \ntemplate <typename _M> struct BidirMonoidTrait<_M, false>\n{\n  using M = _M;\n\
    \  using BS = typename M::S;\n  using S = std::pair<BS, BS>;\n  static constexpr\
    \ S ts(const S &x) { return S(x.second, x.first); }\n  static constexpr S op(const\
    \ S &x, const S &y)\n  {\n    return S{\n        M::op(std::forward<const S>(x.first),\
    \ std::forward<const S>(y.first)),\n        M::op(std::forward<const S>(y.second),\n\
    \              std::forward<const S>(x.second))};\n  }\n  static constexpr const\
    \ S un() { return S{M::un(), M::un()}; }\n  static constexpr S iv(const S &x)\n\
    \  {\n    return S{M::iv(std::forward<const S>(x.first)),\n             M::iv(std::forward<const\
    \ S>(x.second))};\n  }\n  static constexpr S pw(const S &x, u64 y)\n  {\n    return\
    \ S{M::pw(std::forward<const S>(x.first), std::forward<u64>(y)),\n    M::pw(std::forward<const\
    \ S>(x.first), std::forward<u64>(y))};\n  }\n  static constexpr bool cm = false;\n\
    };\n\ntemplate<typename _M, bool _cm = _M::cm> struct BidirActedMonoidTrait {\
    \ };\ntemplate<typename _M> struct BidirActedMonoidTrait<_M, true> : BidirMonoidTrait<_M,\
    \ true>\n{\n  using A = typename M::A;\n  static constexpr S act(const A &a, const\
    \ S &s, u64 len)\n  {\n    return M::act(std::forward<const A>(a), std::forward<const\
    \ S>(s),\n               std::forward<u64>(len));\n  }\n\n};\n\n} // namespace\
    \ mono"
  dependsOn:
  - lib/internal.hpp
  isVerificationFile: false
  path: lib/monoid/monoid_trait.hpp
  requiredBy:
  - lib/ds/segtree.hpp
  - lib/monoid/monoid_add.hpp
  - lib/monoid/monoid_linear_function.hpp
  timestamp: '2024-06-14 19:20:52+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/ds/point_add_range_sum.test.cpp
  - verify/ds/point_set_range_composite.test.cpp
documentation_of: lib/monoid/monoid_trait.hpp
layout: document
redirect_from:
- /library/lib/monoid/monoid_trait.hpp
- /library/lib/monoid/monoid_trait.hpp.html
title: lib/monoid/monoid_trait.hpp
---
