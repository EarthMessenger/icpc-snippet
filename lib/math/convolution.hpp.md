---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/internal.hpp
    title: lib/internal.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/internal.hpp\"\n#include <cmath>\n#include <vector>\n\
    #include <cstring>\n#include <iostream>\n#include <algorithm>\n\nusing i32 = int;\n\
    using i64 = long long;\nusing i128 = __int128_t;\nusing u32 = unsigned int;\n\
    using u64 = unsigned long long;\nusing u128 = __uint128_t;\n\ntemplate<typename\
    \ T> using vec = std::vector<T>;\nusing pii = std::pair<int, int>;\n#line 3 \"\
    lib/math/convolution.hpp\"\n\nnamespace poly {\n\nnamespace details {\n\nvec<u32>\
    \ r[30];\nconst vec<u32> &calc(const u32 n)\n{\n  if (r[n].size()) return r[n];\n\
    \  u32 q = 1 << n, p = q / 2;\n  r[n].resize(q);\n  for (u32 i = 1; i < q; i++)\
    \ {\n    r[n][i] = r[n][i / 2] / 2;\n    if (i % 2) r[n][i] += p;\n  }\n  return\
    \ r[n];\n}\n\n} // namespace details\n\ntemplate <typename T> void reverse_transform(const\
    \ u32 n, vec<T> &a)\n{\n  const auto &r = details::calc(n);\n  u32 q = 1 << n;\n\
    \  for (u32 i = 0; i < q; i++) {\n    if (i < r[i]) std::swap(a[i], a[r[i]]);\n\
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
    \ bit\n\n} // namespace poly\n"
  code: "#pragma once\n#include \"lib/internal.hpp\"\n\nnamespace poly {\n\nnamespace\
    \ details {\n\nvec<u32> r[30];\nconst vec<u32> &calc(const u32 n)\n{\n  if (r[n].size())\
    \ return r[n];\n  u32 q = 1 << n, p = q / 2;\n  r[n].resize(q);\n  for (u32 i\
    \ = 1; i < q; i++) {\n    r[n][i] = r[n][i / 2] / 2;\n    if (i % 2) r[n][i] +=\
    \ p;\n  }\n  return r[n];\n}\n\n} // namespace details\n\ntemplate <typename T>\
    \ void reverse_transform(const u32 n, vec<T> &a)\n{\n  const auto &r = details::calc(n);\n\
    \  u32 q = 1 << n;\n  for (u32 i = 0; i < q; i++) {\n    if (i < r[i]) std::swap(a[i],\
    \ a[r[i]]);\n  }\n}\n\ntemplate <bool d, class B, class I, typename T>\nvoid fourier_transform(const\
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
    \ bit\n\n} // namespace poly"
  dependsOn:
  - lib/internal.hpp
  isVerificationFile: false
  path: lib/math/convolution.hpp
  requiredBy: []
  timestamp: '2024-06-07 20:06:35+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/math/convolution.test.cpp
  - verify/math/bitwise_and_convolution.test.cpp
  - verify/math/bitwise_xor_convolution.test.cpp
  - verify/math/subset_convolution.test.cpp
documentation_of: lib/math/convolution.hpp
layout: document
redirect_from:
- /library/lib/math/convolution.hpp
- /library/lib/math/convolution.hpp.html
title: lib/math/convolution.hpp
---
