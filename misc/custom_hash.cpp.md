---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://xorshift.di.unimi.it/splitmix64.c
  bundledCode: "#line 1 \"misc/custom_hash.cpp\"\n#include <chrono>\n\nstruct custom_hash\
    \ {\n\tstatic uint64_t splitmix64(uint64_t x) {\n\t\t// http://xorshift.di.unimi.it/splitmix64.c\n\
    \t\tx += 0x9e3779b97f4a7c15;\n\t\tx = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n\t\
    \tx = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n\t\treturn x ^ (x >> 31);\n\t}\n\n\
    \tsize_t operator()(uint64_t x) const {\n\t\tstatic const uint64_t FIXED_RANDOM\
    \ = std::chrono::steady_clock::now().time_since_epoch().count();\n\t\treturn splitmix64(x\
    \ + FIXED_RANDOM);\n\t}\n};\n"
  code: "#include <chrono>\n\nstruct custom_hash {\n\tstatic uint64_t splitmix64(uint64_t\
    \ x) {\n\t\t// http://xorshift.di.unimi.it/splitmix64.c\n\t\tx += 0x9e3779b97f4a7c15;\n\
    \t\tx = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n\t\tx = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n\
    \t\treturn x ^ (x >> 31);\n\t}\n\n\tsize_t operator()(uint64_t x) const {\n\t\t\
    static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \t\treturn splitmix64(x + FIXED_RANDOM);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/custom_hash.cpp
  requiredBy: []
  timestamp: '2024-06-06 21:18:13+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/custom_hash.cpp
layout: document
redirect_from:
- /library/misc/custom_hash.cpp
- /library/misc/custom_hash.cpp.html
title: misc/custom_hash.cpp
---
