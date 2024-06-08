---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/internal.hpp
    title: lib/internal.hpp
  - icon: ':heavy_check_mark:'
    path: lib/math/convolution.hpp
    title: lib/math/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: lib/math/static_modint.hpp
    title: lib/math/static_modint.hpp
  - icon: ':heavy_check_mark:'
    path: lib/misc/bitop.hpp
    title: lib/misc/bitop.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"verify/math/convolution.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\
    \n\n#line 2 \"lib/internal.hpp\"\n#include <cmath>\n#include <tuple>\n#include\
    \ <vector>\n#include <utility>\n#include <cstring>\n#include <iostream>\n#include\
    \ <algorithm>\n\nusing i32 = int;\nusing i64 = long long;\nusing i128 = __int128_t;\n\
    using u32 = unsigned int;\nusing u64 = unsigned long long;\nusing u128 = __uint128_t;\n\
    \ntemplate<typename T> using vec = std::vector<T>;\nusing pii = std::pair<int,\
    \ int>;\n#line 3 \"lib/misc/bitop.hpp\"\n\nint clz(u64 x) { return __builtin_clzll(x);\
    \ }\nint ctz(u64 x) { return __builtin_ctzll(x); }\n// floor(log2(x))\nint lg2(u64\
    \ x) { return 63 ^ clz(x); }\n// bit width\nint btw(u64 x) { return lg2(x) + 1;\
    \ }\n// bit ceil\nu64 btc(u64 x) { return (x <= 1 ? 1: 1ull << btw(x - 1)); }\n\
    // bit floor\nu64 btf(u64 x) { return 1ull << lg2(x); }\n// popcount\n__attribute__((target(\"\
    popcnt\")))\nint ppc(u64 x) { return __builtin_popcountll(x); }\n#line 3 \"lib/math/convolution.hpp\"\
    \n\nnamespace poly {\n\nnamespace details {\n\nvec<u32> r[30];\nconst vec<u32>\
    \ &calc(const u32 n)\n{\n  if (r[n].size()) return r[n];\n  u32 q = 1 << n, p\
    \ = q / 2;\n  r[n].resize(q);\n  for (u32 i = 1; i < q; i++) {\n    r[n][i] =\
    \ r[n][i / 2] / 2;\n    if (i % 2) r[n][i] += p;\n  }\n  return r[n];\n}\n\n}\
    \ // namespace details\n\ntemplate <typename T> void reverse_transform(const u32\
    \ n, vec<T> &a)\n{\n  const auto &r = details::calc(n);\n  u32 q = 1 << n;\n \
    \ for (u32 i = 0; i < q; i++) {\n    if (i < r[i]) std::swap(a[i], a[r[i]]);\n\
    \  }\n}\n\ntemplate <bool d, class B, class I, typename T>\nvoid fourier_transform(const\
    \ u32 n, vec<T> &a, B base, I inv, T e)\n{\n  reverse_transform(n, a);\n  u32\
    \ q = 1 << n;\n  for (u32 h = 2; h <= q; h *= 2) {\n    T b = base(h);\n    for\
    \ (u32 j = 0; j < q; j += h) {\n      T w(e);\n      for (u32 k = j, l = h / 2;\
    \ k < j + l; k++) {\n        T u = a[k], v = w * a[k + l];\n        a[k] = u +\
    \ v;\n        a[k + l] = u - v;\n        w = w * b;\n      }\n    }\n  }\n  if\
    \ constexpr (d) {\n    for (u32 i = 0; i < q; i++)\n      inv(a[i], q);\n  }\n\
    }\n\n} // namespace poly\n\nnamespace poly {\n\nnamespace bit {\n\ntemplate <typename\
    \ T> void compliment(u32 n, vec<T> &a)\n{\n  u32 q = 1 << n;\n  for (u32 i = 0;\
    \ i < q; i++) {\n    if (i & 1) std::swap(a[i], a[(~i) & (q - 1)]);\n  }\n}\n\n\
    template <bool dir, typename T> void sosdp(u32 n, vec<T> &a)\n{\n  u32 q = 1 <<\
    \ n;\n  for (u32 i = 0; i < n; i++) {\n    for (u32 j = 0; j < q; j++) {\n   \
    \   if ((j >> i) & 1) {\n        if constexpr (!dir) a[j] += a[j ^ (1 << i)];\n\
    \        else a[j] -= a[j ^ (1 << i)];\n      }\n    }\n  }\n}\n\n} // namespace\
    \ bit\n\n} // namespace poly\n#line 3 \"lib/math/static_modint.hpp\"\n\ntemplate\
    \ <int M>\nstruct static_modint\n{\n  static constexpr u32 UM = M;\n  static_assert(UM\
    \ < 0x80'00'00'00u);\n\n  u32 v;\n  constexpr static_modint() : v(0) {}\n\n  template\
    \ <typename T, std::enable_if_t<std::is_signed_v<T>>* = nullptr>\n  constexpr\
    \ static_modint(T n) : v((n %= M) < 0 ? n + M : n) {}\n\n  template <typename\
    \ T, std::enable_if_t<std::is_unsigned_v<T>>* = nullptr>\n  constexpr static_modint(T\
    \ n) : v(n %= UM) {}\n\n  using mint = static_modint;\n\n  static mint raw(u32\
    \ v)\n  {\n    mint res;\n    res.v = v;\n    return res;\n  }\n\n  constexpr\
    \ u32 val() const { return v; }\n\n  mint operator-() const { return mint::raw(v\
    \ == 0 ? 0u : UM - v); }\n\n  mint &operator+=(mint a)\n  {\n    if ((v += a.v)\
    \ >= UM) v -= UM;\n    return *this;\n  }\n  mint &operator-=(mint a)\n  {\n \
    \   if ((v += UM - a.v) >= UM) v -= UM;\n    return *this;\n  }\n  mint &operator*=(mint\
    \ a)\n  {\n    v = (u64)v * a.v % UM;\n    return *this;\n  }\n  mint &operator/=(mint\
    \ a) { return *this *= a.inv(); }\n\n  friend mint operator+(mint a, mint b) {\
    \ return a += b; }\n  friend mint operator-(mint a, mint b) { return a -= b; }\n\
    \  friend mint operator*(mint a, mint b) { return a *= b; }\n  friend mint operator/(mint\
    \ a, mint b) { return a /= b; }\n\n  mint pow(u64 n) const\n  {\n    mint res\
    \ = 1, base = *this;\n    while (n) {\n      if (n & 1) res *= base;\n      base\
    \ *= base;\n      n >>= 1;\n    }\n    return res;\n  }\n\n  mint inv() const\
    \ { return pow(UM - 2); }\n};\n#line 6 \"verify/math/convolution.test.cpp\"\n\n\
    signed main() \n{\n    using namespace std;\n    ios::sync_with_stdio(false);\
    \ cin.tie(0), cout.tie(0);\n    using mint = static_modint<998244353>;\n    auto\
    \ read_int = [x = int()]() mutable { return cin >> x, x; };\n    u32 n = read_int(),\
    \ m = read_int();\n    u32 p = lg2(max(btc(n), btc(m))) + 1, q = 1 << p;\n   \
    \ vec<mint> a(q), b(q);\n    for (u32 i = 0; i < n; i++) a[i] = read_int();\n\
    \    for (u32 i = 0; i < m; i++) b[i] = read_int();\n    auto base = [](u32 h)\
    \ { return mint::raw(3).pow(998244352 / h); };\n    auto inv = [iv2 = mint(q).inv()](mint\
    \ &x,[[maybe_unused]] u32 y){x *= iv2;};\n    poly::fourier_transform<0>(p, a,\
    \ base, inv, mint::raw(1));\n    poly::fourier_transform<0>(p, b, base, inv, mint::raw(1));\n\
    \    for (u32 i = 0; i < q; i++) a[i] *= b[i];\n    poly::fourier_transform<1>(p,\
    \ a, base, inv, mint::raw(1));\n    reverse(a.begin() + 1, a.end());\n    for\
    \ (u32 i = 0; i < n + m - 1; i++) cout << a[i].val() << ' ';\n    cout << '\\\
    n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ \"lib/misc/bitop.hpp\"\n#include \"lib/math/convolution.hpp\"\n#include \"lib/math/static_modint.hpp\"\
    \n\nsigned main() \n{\n    using namespace std;\n    ios::sync_with_stdio(false);\
    \ cin.tie(0), cout.tie(0);\n    using mint = static_modint<998244353>;\n    auto\
    \ read_int = [x = int()]() mutable { return cin >> x, x; };\n    u32 n = read_int(),\
    \ m = read_int();\n    u32 p = lg2(max(btc(n), btc(m))) + 1, q = 1 << p;\n   \
    \ vec<mint> a(q), b(q);\n    for (u32 i = 0; i < n; i++) a[i] = read_int();\n\
    \    for (u32 i = 0; i < m; i++) b[i] = read_int();\n    auto base = [](u32 h)\
    \ { return mint::raw(3).pow(998244352 / h); };\n    auto inv = [iv2 = mint(q).inv()](mint\
    \ &x,[[maybe_unused]] u32 y){x *= iv2;};\n    poly::fourier_transform<0>(p, a,\
    \ base, inv, mint::raw(1));\n    poly::fourier_transform<0>(p, b, base, inv, mint::raw(1));\n\
    \    for (u32 i = 0; i < q; i++) a[i] *= b[i];\n    poly::fourier_transform<1>(p,\
    \ a, base, inv, mint::raw(1));\n    reverse(a.begin() + 1, a.end());\n    for\
    \ (u32 i = 0; i < n + m - 1; i++) cout << a[i].val() << ' ';\n    cout << '\\\
    n';\n    return 0;\n}"
  dependsOn:
  - lib/misc/bitop.hpp
  - lib/internal.hpp
  - lib/math/convolution.hpp
  - lib/math/static_modint.hpp
  isVerificationFile: true
  path: verify/math/convolution.test.cpp
  requiredBy: []
  timestamp: '2024-06-08 15:08:56+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/math/convolution.test.cpp
layout: document
redirect_from:
- /verify/verify/math/convolution.test.cpp
- /verify/verify/math/convolution.test.cpp.html
title: verify/math/convolution.test.cpp
---
