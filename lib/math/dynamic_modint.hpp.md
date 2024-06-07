---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/internal.hpp
    title: lib/internal.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/internal.hpp\"\n#include <cmath>\n#include <vector>\n\
    #include <cstring>\n#include <iostream>\n#include <algorithm>\n\nusing i32 = int;\n\
    using i64 = long long;\nusing i128 = __int128_t;\nusing u32 = unsigned int;\n\
    using u64 = unsigned long long;\nusing u128 = __uint128_t;\n\ntemplate<typename\
    \ T> using vec = std::vector<T>;\nusing pii = std::pair<int, int>;\n#line 3 \"\
    lib/math/dynamic_modint.hpp\"\n\nstruct barrett {\n  u32 m;\n  u64 im;\n\n  barrett()\
    \ {}\n  barrett(u32 m) : m(m), im((u64)(-1) / m + 1) {}\n\n  u32 mod() const {\
    \ return m; }\n\n  u32 reduce(u64 x) const \n  {\n    u64 y = ((u128)x * im) >>\
    \ 64;\n    u32 z = x - y * m;\n    if (z >= m) z += m;\n    return z;\n  }\n};\n\
    \ntemplate <int id>\nstruct dynamic_modint\n{\n  static barrett b;\n  static u32\
    \ mod() { return b.m; }\n  static void set_mod(u32 x) { b = barrett(x); }\n  static\
    \ u32 reduce(u64 x) { return b.reduce(x); }\n\n  u32 v;\n\n  dynamic_modint()\
    \ = default; // as a trivial struct\n  template <typename T>\n    dynamic_modint(T\
    \ x) : v((x % (T)mod() < 0) ? x + (T)mod() : x) {}\n\n  using mint = dynamic_modint;\n\
    \n  static mint raw(u32 x)\n  {\n    mint res;\n    res.v = x;\n    return res;\n\
    \  }\n\n  u32 val() const { return v; }\n\n  mint operator-() const { return dynamic_modint(mod()\
    \ - v); }\n  mint &operator+=(mint x)\n  {\n    if ((v += x.v) >= mod()) v -=\
    \ mod();\n    return *this;\n  }\n  mint &operator-=(mint x)\n  {\n    if ((v\
    \ += mod() - x.v) >= mod()) v -= mod();\n    return *this;\n  }\n  mint &operator*=(mint\
    \ x)\n  {\n    v = reduce((u64)v * x.v);\n    return *this;\n  }\n  friend mint\
    \ operator+(mint x, mint y) { return x += y; }\n  friend mint operator-(mint x,\
    \ mint y) { return x -= y; }\n  friend mint operator*(mint x, mint y) { return\
    \ x *= y; }\n\n  mint pow(long long y) const\n  {\n    mint res = 1;\n    mint\
    \ base = *this;\n    while (y) {\n      if (y & 1) res *= base;\n      base *=\
    \ base;\n      y >>= 1;\n    }\n    return res;\n  }\n\n  mint inv() const { return\
    \ pow(mod() - 2); }\n\n  mint &operator/=(mint x) { return *this *= x.inv(); }\n\
    \  friend mint operator/(mint x, mint y) { return x *= y.inv(); }\n};\n\ntemplate\
    \ <int id> barrett dynamic_modint<id>::b;\n"
  code: "#pragma once\n#include \"lib/internal.hpp\"\n\nstruct barrett {\n  u32 m;\n\
    \  u64 im;\n\n  barrett() {}\n  barrett(u32 m) : m(m), im((u64)(-1) / m + 1) {}\n\
    \n  u32 mod() const { return m; }\n\n  u32 reduce(u64 x) const \n  {\n    u64\
    \ y = ((u128)x * im) >> 64;\n    u32 z = x - y * m;\n    if (z >= m) z += m;\n\
    \    return z;\n  }\n};\n\ntemplate <int id>\nstruct dynamic_modint\n{\n  static\
    \ barrett b;\n  static u32 mod() { return b.m; }\n  static void set_mod(u32 x)\
    \ { b = barrett(x); }\n  static u32 reduce(u64 x) { return b.reduce(x); }\n\n\
    \  u32 v;\n\n  dynamic_modint() = default; // as a trivial struct\n  template\
    \ <typename T>\n    dynamic_modint(T x) : v((x % (T)mod() < 0) ? x + (T)mod()\
    \ : x) {}\n\n  using mint = dynamic_modint;\n\n  static mint raw(u32 x)\n  {\n\
    \    mint res;\n    res.v = x;\n    return res;\n  }\n\n  u32 val() const { return\
    \ v; }\n\n  mint operator-() const { return dynamic_modint(mod() - v); }\n  mint\
    \ &operator+=(mint x)\n  {\n    if ((v += x.v) >= mod()) v -= mod();\n    return\
    \ *this;\n  }\n  mint &operator-=(mint x)\n  {\n    if ((v += mod() - x.v) >=\
    \ mod()) v -= mod();\n    return *this;\n  }\n  mint &operator*=(mint x)\n  {\n\
    \    v = reduce((u64)v * x.v);\n    return *this;\n  }\n  friend mint operator+(mint\
    \ x, mint y) { return x += y; }\n  friend mint operator-(mint x, mint y) { return\
    \ x -= y; }\n  friend mint operator*(mint x, mint y) { return x *= y; }\n\n  mint\
    \ pow(long long y) const\n  {\n    mint res = 1;\n    mint base = *this;\n   \
    \ while (y) {\n      if (y & 1) res *= base;\n      base *= base;\n      y >>=\
    \ 1;\n    }\n    return res;\n  }\n\n  mint inv() const { return pow(mod() - 2);\
    \ }\n\n  mint &operator/=(mint x) { return *this *= x.inv(); }\n  friend mint\
    \ operator/(mint x, mint y) { return x *= y.inv(); }\n};\n\ntemplate <int id>\
    \ barrett dynamic_modint<id>::b;\n"
  dependsOn:
  - lib/internal.hpp
  isVerificationFile: false
  path: lib/math/dynamic_modint.hpp
  requiredBy: []
  timestamp: '2024-06-07 18:17:19+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/dynamic_modint.hpp
layout: document
redirect_from:
- /library/lib/math/dynamic_modint.hpp
- /library/lib/math/dynamic_modint.hpp.html
title: lib/math/dynamic_modint.hpp
---
