---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://xorshift.di.unimi.it/splitmix64.c
  bundledCode: "#line 1 \"lib/misc/custom_hash.hpp\"\n#include <chrono>\n\nstruct\
    \ custom_hash\n{\n  static uint64_t splitmix64(uint64_t x)\n  {\n    // http://xorshift.di.unimi.it/splitmix64.c\n\
    \    x += 0x9e3779b97f4a7c15;\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n\
    \    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n    return x ^ (x >> 31);\n  }\n\
    \n  size_t operator()(uint64_t x) const\n  {\n    static const uint64_t FIXED_RANDOM\
    \ =\n        std::chrono::steady_clock::now().time_since_epoch().count();\n  \
    \  return splitmix64(x + FIXED_RANDOM);\n  }\n};\n"
  code: "#include <chrono>\n\nstruct custom_hash\n{\n  static uint64_t splitmix64(uint64_t\
    \ x)\n  {\n    // http://xorshift.di.unimi.it/splitmix64.c\n    x += 0x9e3779b97f4a7c15;\n\
    \    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n\
    \    return x ^ (x >> 31);\n  }\n\n  size_t operator()(uint64_t x) const\n  {\n\
    \    static const uint64_t FIXED_RANDOM =\n        std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \    return splitmix64(x + FIXED_RANDOM);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/misc/custom_hash.hpp
  requiredBy: []
  timestamp: '2024-06-07 16:37:49+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/misc/custom_hash.hpp
layout: document
redirect_from:
- /library/lib/misc/custom_hash.hpp
- /library/lib/misc/custom_hash.hpp.html
title: lib/misc/custom_hash.hpp
---
