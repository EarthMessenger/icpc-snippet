---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/internal.hpp
    title: Internal Definition
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/ds/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
    title: verify/ds/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
  - icon: ':x:'
    path: verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp
    title: verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/ds/point_set_range_composite.test.cpp
    title: verify/ds/point_set_range_composite.test.cpp
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
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Static Modint
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
  code: "#pragma once\n#include \"lib/internal.hpp\"\n\n/**\n * @brief Static Modint\n\
    \ *\n * @tparam M modulo\n */\ntemplate <int M> struct static_modint\n{\n  static\
    \ constexpr u32 UM = M;\n  static_assert(UM < 0x80'00'00'00u);\n\n  u32 v;\n \
    \ constexpr static_modint() : v(0) {}\n\n  template <typename T, std::enable_if_t<std::is_signed_v<T>>\
    \ * = nullptr>\n  constexpr static_modint(T n) : v((n %= M) < 0 ? n + M : n)\n\
    \  {\n  }\n\n  template <typename T, std::enable_if_t<std::is_unsigned_v<T>> *\
    \ = nullptr>\n  constexpr static_modint(T n) : v(n %= UM)\n  {\n  }\n\n  using\
    \ mint = static_modint;\n\n  static mint raw(u32 v)\n  {\n    mint res;\n    res.v\
    \ = v;\n    return res;\n  }\n\n  constexpr u32 val() const { return v; }\n\n\
    \  mint operator-() const { return mint::raw(v == 0 ? 0u : UM - v); }\n\n  mint\
    \ &operator+=(mint a)\n  {\n    if ((v += a.v) >= UM) v -= UM;\n    return *this;\n\
    \  }\n  mint &operator-=(mint a)\n  {\n    if ((v += UM - a.v) >= UM) v -= UM;\n\
    \    return *this;\n  }\n  mint &operator*=(mint a)\n  {\n    v = (u64)v * a.v\
    \ % UM;\n    return *this;\n  }\n  mint &operator/=(mint a) { return *this *=\
    \ a.inv(); }\n\n  friend mint operator+(mint a, mint b) { return a += b; }\n \
    \ friend mint operator-(mint a, mint b) { return a -= b; }\n  friend mint operator*(mint\
    \ a, mint b) { return a *= b; }\n  friend mint operator/(mint a, mint b) { return\
    \ a /= b; }\n  friend bool operator==(mint a, mint b) { return a.val() == b.val();\
    \ }\n  friend bool operator!=(mint a, mint b) { return a.val() != b.val(); }\n\
    \  friend std::istream operator>>(std::istream &in, mint x) { return in >> x.v;\
    \ }\n  friend std::ostream operator>>(std::ostream &out, mint x)\n  {\n    return\
    \ out << x.v;\n  }\n\n  mint pow(u64 n) const\n  {\n    mint res = 1, base = *this;\n\
    \    while (n) {\n      if (n & 1) res *= base;\n      base *= base;\n      n\
    \ >>= 1;\n    }\n    return res;\n  }\n\n  mint inv() const { return pow(UM -\
    \ 2); }\n};\n"
  dependsOn:
  - lib/internal.hpp
  isVerificationFile: false
  path: lib/math/static_modint.hpp
  requiredBy: []
  timestamp: '2024-06-14 19:20:52+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  - verify/ds/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
  - verify/ds/point_set_range_composite.test.cpp
  - verify/math/convolution.test.cpp
  - verify/math/bitwise_and_convolution.test.cpp
  - verify/math/bitwise_xor_convolution.test.cpp
  - verify/math/subset_convolution.test.cpp
documentation_of: lib/math/static_modint.hpp
layout: document
redirect_from:
- /library/lib/math/static_modint.hpp
- /library/lib/math/static_modint.hpp.html
title: Static Modint
---
