---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/str/z.hpp
    title: lib/str/z.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"verify/str/zalgorithm.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \n\n#include <iostream>\n#include <string>\n#line 1 \"lib/str/z.hpp\"\n#include\
    \ <vector>\n#line 3 \"lib/str/z.hpp\"\n\nstd::vector<int> z_algorithm(const std::string\
    \ &s)\n{\n  int n = s.size();\n  std::vector<int> z(n + 1);\n  z[0] = n;\n  int\
    \ l = 0, r = 0;\n  for (int i = 1; i <= n; i++) {\n    int t = 0;\n    if (i <=\
    \ r) t = std::min(z[i - l], r - i);\n    while (i + t < n && s[t] == s[i + t])\
    \ t++;\n    z[i] = t;\n    if (i + z[i] > r) {\n      l = i;\n      r = i + z[i];\n\
    \    }\n  }\n  return z;\n}\n#line 6 \"verify/str/zalgorithm.test.cpp\"\n\nint\
    \ main()\n{\n  std::string s;\n  std::cin >> s;\n  auto res = z_algorithm(s);\n\
    \  res.pop_back();\n  for (auto i : res) std::cout << i << \" \";\n  std::cout\
    \ << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ <iostream>\n#include <string>\n#include \"lib/str/z.hpp\"\n\nint main()\n{\n\
    \  std::string s;\n  std::cin >> s;\n  auto res = z_algorithm(s);\n  res.pop_back();\n\
    \  for (auto i : res) std::cout << i << \" \";\n  std::cout << std::endl;\n}\n"
  dependsOn:
  - lib/str/z.hpp
  isVerificationFile: true
  path: verify/str/zalgorithm.test.cpp
  requiredBy: []
  timestamp: '2024-06-14 20:43:15+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/str/zalgorithm.test.cpp
layout: document
redirect_from:
- /verify/verify/str/zalgorithm.test.cpp
- /verify/verify/str/zalgorithm.test.cpp.html
title: verify/str/zalgorithm.test.cpp
---
