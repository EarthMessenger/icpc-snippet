---
data:
  _extendedDependsOn:
  - icon: ':warning:'
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
    \ T> using vec = std::vector<T>;\nusing pii = std::pair<int, int>;\n#line 2 \"\
    lib/math/fast_gcd.hpp\"\n\nint gcd(int a, int b)\n{\n  int az = __builtin_ctz(a);\n\
    \  int bz = __builtin_ctz(b);\n  int z = std::min(az, bz);\n  b >>= bz;\n  while\
    \ (a) {\n    a >>= az;\n    int diff = a - b;\n    az = __builtin_ctz(diff);\n\
    \    b = std::min(a, b);\n    a = std::abs(diff);\n  }\n  return b << z;\n}\n"
  code: "#include \"lib/internal.hpp\"\n\nint gcd(int a, int b)\n{\n  int az = __builtin_ctz(a);\n\
    \  int bz = __builtin_ctz(b);\n  int z = std::min(az, bz);\n  b >>= bz;\n  while\
    \ (a) {\n    a >>= az;\n    int diff = a - b;\n    az = __builtin_ctz(diff);\n\
    \    b = std::min(a, b);\n    a = std::abs(diff);\n  }\n  return b << z;\n}"
  dependsOn:
  - lib/internal.hpp
  isVerificationFile: false
  path: lib/math/fast_gcd.hpp
  requiredBy: []
  timestamp: '2024-06-07 15:38:59+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/fast_gcd.hpp
layout: document
redirect_from:
- /library/lib/math/fast_gcd.hpp
- /library/lib/math/fast_gcd.hpp.html
title: lib/math/fast_gcd.hpp
---
