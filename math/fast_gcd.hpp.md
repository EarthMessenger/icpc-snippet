---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/fast_gcd.hpp\"\n#include <algorithm>\n\nint gcd(int\
    \ a, int b)\n{\n\tint az = __builtin_ctz(a);\n\tint bz = __builtin_ctz(b);\n\t\
    int z = std::min(az, bz);\n\tb >>= bz;\n\twhile (a) {\n\t\ta >>= az;\n\t\tint\
    \ diff = a - b;\n\t\taz = __builtin_ctz(diff);\n\t\tb = std::min(a, b);\n\t\t\
    a = std::abs(diff);\n\t}\n\treturn b << z;\n}\n"
  code: "#include <algorithm>\n\nint gcd(int a, int b)\n{\n\tint az = __builtin_ctz(a);\n\
    \tint bz = __builtin_ctz(b);\n\tint z = std::min(az, bz);\n\tb >>= bz;\n\twhile\
    \ (a) {\n\t\ta >>= az;\n\t\tint diff = a - b;\n\t\taz = __builtin_ctz(diff);\n\
    \t\tb = std::min(a, b);\n\t\ta = std::abs(diff);\n\t}\n\treturn b << z;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/fast_gcd.hpp
  requiredBy: []
  timestamp: '2024-06-06 21:18:13+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fast_gcd.hpp
layout: document
redirect_from:
- /library/math/fast_gcd.hpp
- /library/math/fast_gcd.hpp.html
title: math/fast_gcd.hpp
---
