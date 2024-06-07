---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/internal.hpp
    title: lib/internal.hpp
  - icon: ':question:'
    path: lib/math/convolution.hpp
    title: lib/math/convolution.hpp
  - icon: ':question:'
    path: lib/math/static_modint.hpp
    title: lib/math/static_modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_and_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_and_convolution
  bundledCode: "#line 1 \"verify/math/bitwise_and_convolution.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\n\n#line\
    \ 2 \"lib/internal.hpp\"\n#include <cmath>\n#include <vector>\n#include <cstring>\n\
    #include <iostream>\n#include <algorithm>\n\nusing i32 = int;\nusing i64 = long\
    \ long;\nusing i128 = __int128_t;\nusing u32 = unsigned int;\nusing u64 = unsigned\
    \ long long;\nusing u128 = __uint128_t;\n\ntemplate<typename T> using vec = std::vector<T>;\n\
    using pii = std::pair<int, int>;\n#line 3 \"lib/math/convolution.hpp\"\n\nnamespace\
    \ poly {\n\nnamespace details {\n\nvec<u32> r[30];\nconst vec<u32> &calc(const\
    \ u32 n)\n{\n  if (r[n].size()) return r[n];\n  u32 q = 1 << n, p = q / 2;\n \
    \ r[n].resize(q);\n  for (u32 i = 1; i < q; i++) {\n    r[n][i] = r[n][i / 2]\
    \ / 2;\n    if (i % 2) r[n][i] += p;\n  }\n  return r[n];\n}\n\n} // namespace\
    \ details\n\ntemplate <typename T> void reverse_transform(const u32 n, vec<T>\
    \ &a)\n{\n  const auto &r = details::calc(n);\n  u32 q = 1 << n;\n  for (u32 i\
    \ = 0; i < q; i++) {\n    if (i < r[i]) std::swap(a[i], a[r[i]]);\n  }\n}\n\n\
    template <bool d, class B, class I, typename T>\nvoid fourier_transform(const\
    \ u32 n, vec<T> &a, B base, I inv, T e)\n{\n  reverse_transform(n, a);\n  u32\
    \ q = 1 << n;\n  for (u32 h = 2; h <= q; h *= 2) {\n    T b = base(h);\n    for\
    \ (u32 j = 0; j < q; j += h) {\n      T w(e);\n      for (u32 k = j, l = h / 2;\
    \ k < j + l; k++) {\n        T u = a[k], v = w * a[k + l];\n        a[k] = u +\
    \ v;\n        a[k + l] = u - v;\n        w = w * b;\n      }\n    }\n  }\n  if\
    \ (d) {\n    for (u32 i = 0; i < q; i++)\n      inv(a[i], q);\n  }\n}\n\n} //\
    \ namespace poly\n\nnamespace poly {\n\nnamespace bit {\n\ntemplate <typename\
    \ T> void compliment(u32 n, vec<T> &a)\n{\n  u32 q = 1 << n;\n  for (u32 i = 0;\
    \ i < q; i++) {\n    if (i & 1) std::swap(a[i], a[(~i) & (q - 1)]);\n  }\n}\n\n\
    template <bool dir, typename T> void sosdp(u32 n, vec<T> &a)\n{\n  u32 q = 1 <<\
    \ n;\n  for (u32 i = 0; i < n; i++) {\n    for (u32 j = 0; j < q; j++) {\n   \
    \   if ((j >> i) & 1) {\n        if (!dir) a[j] += a[j ^ (1 << i)];\n        else\
    \ a[j] -= a[j ^ (1 << i)];\n      }\n    }\n  }\n}\n\n} // namespace bit\n\n}\
    \ // namespace poly\n#line 3 \"lib/math/static_modint.hpp\"\n\ntemplate <int M>\n\
    struct static_modint\n{\n  static constexpr u32 UM = M;\n  static_assert(UM <\
    \ 0x80'00'00'00u);\n\n  u32 v;\n  constexpr static_modint() : v(0) {}\n\n  template\
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
    \ { return pow(UM - 2); }\n};\n#line 5 \"verify/math/bitwise_and_convolution.test.cpp\"\
    \n\nsigned main() \n{\n    using namespace std;\n    ios::sync_with_stdio(false);\
    \ \n    cin.tie(0), cout.tie(0);\n    u32 n;\n    cin >> n;\n    using mint =\
    \ static_modint<998244353>;\n    vec<mint> a(1 << n), b(1 << n);\n    auto read_int\
    \ = [x = int()]() mutable { cin >> x; return x; };\n    for (auto &i: a) i = read_int();\n\
    \    for (auto &i: b) i = read_int();\n    poly::bit::compliment(n, a);\n    poly::bit::compliment(n,\
    \ b);\n    poly::bit::sosdp<0>(n, a);\n    poly::bit::sosdp<0>(n, b);\n    for\
    \ (u32 i = 0; i < (1u << n); i++) a[i] *= b[i];\n    poly::bit::sosdp<1>(n, a);\n\
    \    poly::bit::compliment(n, a);\n    for (auto i: a) cout << i.val() << ' ';\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\
    \n\n#include \"lib/math/convolution.hpp\"\n#include \"lib/math/static_modint.hpp\"\
    \n\nsigned main() \n{\n    using namespace std;\n    ios::sync_with_stdio(false);\
    \ \n    cin.tie(0), cout.tie(0);\n    u32 n;\n    cin >> n;\n    using mint =\
    \ static_modint<998244353>;\n    vec<mint> a(1 << n), b(1 << n);\n    auto read_int\
    \ = [x = int()]() mutable { cin >> x; return x; };\n    for (auto &i: a) i = read_int();\n\
    \    for (auto &i: b) i = read_int();\n    poly::bit::compliment(n, a);\n    poly::bit::compliment(n,\
    \ b);\n    poly::bit::sosdp<0>(n, a);\n    poly::bit::sosdp<0>(n, b);\n    for\
    \ (u32 i = 0; i < (1u << n); i++) a[i] *= b[i];\n    poly::bit::sosdp<1>(n, a);\n\
    \    poly::bit::compliment(n, a);\n    for (auto i: a) cout << i.val() << ' ';\n\
    \    return 0;\n}"
  dependsOn:
  - lib/math/convolution.hpp
  - lib/internal.hpp
  - lib/math/static_modint.hpp
  isVerificationFile: true
  path: verify/math/bitwise_and_convolution.test.cpp
  requiredBy: []
  timestamp: '2024-06-07 18:17:19+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/math/bitwise_and_convolution.test.cpp
layout: document
redirect_from:
- /verify/verify/math/bitwise_and_convolution.test.cpp
- /verify/verify/math/bitwise_and_convolution.test.cpp.html
title: verify/math/bitwise_and_convolution.test.cpp
---
