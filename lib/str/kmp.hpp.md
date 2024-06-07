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
    lib/str/kmp.hpp\"\n\nstd::vector<int> prefix_function(const std::string &s)\n\
    {\n  int n = s.size();\n  std::vector<int> p(n + 1);\n  p[0] = p[1] = 0;\n  for\
    \ (int i = 1; i < n; i++) {\n    int t = p[i];\n    while (t > 0 && s[t] != s[i])\
    \ t = p[t];\n    if (s[t] == s[i]) t++;\n    p[i + 1] = t;\n  }\n  return p;\n\
    }\n"
  code: "#pragma once\n#include \"lib/internal.hpp\"\n\nstd::vector<int> prefix_function(const\
    \ std::string &s)\n{\n  int n = s.size();\n  std::vector<int> p(n + 1);\n  p[0]\
    \ = p[1] = 0;\n  for (int i = 1; i < n; i++) {\n    int t = p[i];\n    while (t\
    \ > 0 && s[t] != s[i]) t = p[t];\n    if (s[t] == s[i]) t++;\n    p[i + 1] = t;\n\
    \  }\n  return p;\n}\n"
  dependsOn:
  - lib/internal.hpp
  isVerificationFile: false
  path: lib/str/kmp.hpp
  requiredBy: []
  timestamp: '2024-06-07 18:17:19+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/str/kmp.hpp
layout: document
redirect_from:
- /library/lib/str/kmp.hpp
- /library/lib/str/kmp.hpp.html
title: lib/str/kmp.hpp
---
