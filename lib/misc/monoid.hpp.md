---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/internal.hpp
    title: Internal Definition
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/ds/segtree.hpp
    title: Segment Tree
  _extendedVerifiedWith:
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
  code: "#pragma once\n#include \"lib/internal.hpp\"\n#include <functional>\n\nnamespace\
    \ mono {\n\n// Transfer functor into function to solve errors in c++17.\ntemplate\
    \ <typename Functor, class... Args> auto ftf(const Args &&...args)\n{\n  static\
    \ Functor f;\n  return f(std::forward<const Args>(args)...);\n}\n// default unit\
    \ function\ntemplate <typename T> constexpr const T dunf() { return T(); }\n//\
    \ default inverse functino\ntemplate <typename T, auto U, auto D> constexpr T\
    \ divf(const T &&x)\n{\n  return D(std::forward<const T>(U()), std::forward<const\
    \ T>(x));\n}\n// default power function\ntemplate <typename T, auto O, auto U>\
    \ constexpr T dpwf(T &&x, u64 y)\n{\n  T r = U();\n  for (; y; y /= 2) {\n   \
    \ if (y & 1) r = O(std::forward<const T>(r), std::forward<const T>(x));\n    x\
    \ = O(std::forward<const T>(x), std::forward<const T>(x));\n  }\n  return r;\n\
    }\n\ntemplate <typename T, auto O = ftf<std::multiplies<T>, T, T>, auto E = dunf<T>,\n\
    \          auto P = dpwf<T, O, E>, auto I = nullptr, bool C = false>\nstruct MonoidTrait\n\
    {\n  using S = T;\n  static constexpr S op(const S &x, const S &y)\n  {\n    return\
    \ O(std::forward<const S>(x), std::forward<const S>(y));\n  }\n  static constexpr\
    \ const S un() { return E(); }\n  static constexpr S iv(const S &x) { return I(std::forward<const\
    \ S>(x)); }\n  static constexpr S pw(S &&x, u64 y)\n  {\n    return P(std::forward<S>(x),\
    \ y);\n  }\n  static constexpr bool cm = C;\n};\n\ntemplate <typename T> using\
    \ AddMonoid = MonoidTrait<T, ftf<std::plus<T>, T, T>>;\n\ntemplate <typename _MS,\
    \ typename _MA, auto _AP> struct ActedMonoidTrait\n{\n  using MS = _MS;\n  using\
    \ MA = _MA;\n  using S = typename MS::S;\n  using A = typename MA::A;\n  static\
    \ constexpr S act(const S &s, const A &a, u64 len) \n  { \n    return _AP(std::forward<const\
    \ S>(s), std::forward<const A>(a), len); \n  }\n};\n\n} // namespace mono"
  dependsOn:
  - lib/internal.hpp
  isVerificationFile: false
  path: lib/misc/monoid.hpp
  requiredBy:
  - lib/ds/segtree.hpp
  timestamp: '2024-06-14 09:23:51+08:00'
  verificationStatus: LIBRARY_ALL_AC
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
