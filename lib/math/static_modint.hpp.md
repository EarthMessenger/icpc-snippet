---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/internal.hpp
    title: lib/internal.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/ds/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
    title: verify/ds/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp
    title: verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/internal.hpp\"\n#include <cmath>\n#include <vector>\n\
    #include <cstring>\n#include <iostream>\n#include <algorithm>\n\nusing i32 = int;\n\
    using i64 = long long;\nusing i128 = __int128_t;\nusing u32 = unsigned int;\n\
    using u64 = unsigned long long;\nusing u128 = __uint128_t;\n\ntemplate<typename\
    \ T> using vec = std::vector<T>;\nusing pii = std::pair<int, int>;\n#line 2 \"\
    lib/math/static_modint.hpp\"\n\ntemplate <int M>\nstruct static_modint\n{\n  static\
    \ constexpr u32 UM = M;\n  static_assert(UM < 0x80'00'00'00u);\n\n  u32 v;\n \
    \ constexpr static_modint() : v(0) {}\n\n  template <typename T, std::enable_if_t<std::is_signed_v<T>>*\
    \ = nullptr>\n  constexpr static_modint(T n) : v((n %= M) < 0 ? n + M : n) {}\n\
    \n  template <typename T, std::enable_if_t<std::is_unsigned_v<T>>* = nullptr>\n\
    \  constexpr static_modint(T n) : v(n %= UM) {}\n\n  using mint = static_modint;\n\
    \n  static mint raw(u32 v)\n  {\n    mint res;\n    res.v = v;\n    return res;\n\
    \  }\n\n  constexpr u32 val() const { return v; }\n\n  mint operator-() const\
    \ { return mint::raw(v == 0 ? 0u : UM - v); }\n\n  mint &operator+=(mint a)\n\
    \  {\n    if ((v += a.v) >= UM) v -= UM;\n    return *this;\n  }\n  mint &operator-=(mint\
    \ a)\n  {\n    if ((v += UM - a.v) >= UM) v -= UM;\n    return *this;\n  }\n \
    \ mint &operator*=(mint a)\n  {\n    v = (u64)v * a.v % UM;\n    return *this;\n\
    \  }\n  mint &operator/=(mint a) { return *this *= a.inv(); }\n\n  friend mint\
    \ operator+(mint a, mint b) { return a += b; }\n  friend mint operator-(mint a,\
    \ mint b) { return a -= b; }\n  friend mint operator*(mint a, mint b) { return\
    \ a *= b; }\n  friend mint operator/(mint a, mint b) { return a /= b; }\n\n  mint\
    \ pow(u64 n) const\n  {\n    mint res = 1, base = *this;\n    while (n) {\n  \
    \    if (n & 1) res *= base;\n      base *= base;\n      n >>= 1;\n    }\n   \
    \ return res;\n  }\n\n  mint inv() const { return pow(UM - 2); }\n};\n"
  code: "#include \"lib/internal.hpp\"\n\ntemplate <int M>\nstruct static_modint\n\
    {\n  static constexpr u32 UM = M;\n  static_assert(UM < 0x80'00'00'00u);\n\n \
    \ u32 v;\n  constexpr static_modint() : v(0) {}\n\n  template <typename T, std::enable_if_t<std::is_signed_v<T>>*\
    \ = nullptr>\n  constexpr static_modint(T n) : v((n %= M) < 0 ? n + M : n) {}\n\
    \n  template <typename T, std::enable_if_t<std::is_unsigned_v<T>>* = nullptr>\n\
    \  constexpr static_modint(T n) : v(n %= UM) {}\n\n  using mint = static_modint;\n\
    \n  static mint raw(u32 v)\n  {\n    mint res;\n    res.v = v;\n    return res;\n\
    \  }\n\n  constexpr u32 val() const { return v; }\n\n  mint operator-() const\
    \ { return mint::raw(v == 0 ? 0u : UM - v); }\n\n  mint &operator+=(mint a)\n\
    \  {\n    if ((v += a.v) >= UM) v -= UM;\n    return *this;\n  }\n  mint &operator-=(mint\
    \ a)\n  {\n    if ((v += UM - a.v) >= UM) v -= UM;\n    return *this;\n  }\n \
    \ mint &operator*=(mint a)\n  {\n    v = (u64)v * a.v % UM;\n    return *this;\n\
    \  }\n  mint &operator/=(mint a) { return *this *= a.inv(); }\n\n  friend mint\
    \ operator+(mint a, mint b) { return a += b; }\n  friend mint operator-(mint a,\
    \ mint b) { return a -= b; }\n  friend mint operator*(mint a, mint b) { return\
    \ a *= b; }\n  friend mint operator/(mint a, mint b) { return a /= b; }\n\n  mint\
    \ pow(u64 n) const\n  {\n    mint res = 1, base = *this;\n    while (n) {\n  \
    \    if (n & 1) res *= base;\n      base *= base;\n      n >>= 1;\n    }\n   \
    \ return res;\n  }\n\n  mint inv() const { return pow(UM - 2); }\n};\n"
  dependsOn:
  - lib/internal.hpp
  isVerificationFile: false
  path: lib/math/static_modint.hpp
  requiredBy: []
  timestamp: '2024-06-07 16:37:49+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  - verify/ds/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
documentation_of: lib/math/static_modint.hpp
layout: document
redirect_from:
- /library/lib/math/static_modint.hpp
- /library/lib/math/static_modint.hpp.html
title: lib/math/static_modint.hpp
---
