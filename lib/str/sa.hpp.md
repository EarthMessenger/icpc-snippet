---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/str/longest_common_substring.test.cpp
    title: verify/str/longest_common_substring.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/str/number_of_substrings.test.cpp
    title: verify/str/number_of_substrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/str/suffixarray.test.cpp
    title: verify/str/suffixarray.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/str/sa.hpp\"\n\n#include <vector>\n#include <string>\n\
    #include <utility>\n\n// 0-indexed\nstd::pair<std::vector<int>, std::vector<int>>\
    \ suffix_array(const std::string &s)\n{\n  int n = s.size();\n  int m = std::max(128,\
    \ n);\n\n  std::vector<int> sa(n), rk(n), sa2(n), rk2(n * 2, -1), cnt(m + 1);\n\
    \  for (int i = 0; i < n; i++) rk[i] = s[i];\n  for (int i = 0; i < n; i++) cnt[rk[i]\
    \ + 1]++;\n  for (int i = 1; i < m; i++) cnt[i] += cnt[i - 1];\n  for (int i =\
    \ 0; i < n; i++) sa[cnt[rk[i]]++] = i;\n\n  for (int w = 1;; w *= 2) {\n    int\
    \ p = 0;\n    for (int i = n - w; i < n; i++) sa2[p++] = i;\n    for (int i =\
    \ 0; i < n; i++) {\n      if (sa[i] >= w) sa2[p++] = sa[i] - w;\n    }\n\n   \
    \ std::fill(cnt.begin(), cnt.end(), 0);\n    for (int i = 0; i < n; i++) cnt[rk[sa2[i]]\
    \ + 1]++;\n    for (int i = 1; i < m; i++) cnt[i] += cnt[i - 1];\n    for (int\
    \ i = 0; i < n; i++) sa[cnt[rk[sa2[i]]]++] = sa2[i];\n\n    std::copy(rk.begin(),\
    \ rk.end(), rk2.begin());\n    int q = 0;\n    rk[sa[0]] = 0;\n    for (int i\
    \ = 1; i < n; i++) {\n      int u = sa[i - 1], v = sa[i];\n      if (rk2[u] !=\
    \ rk2[v] || rk2[u + w] != rk2[v + w]) q++;\n      rk[sa[i]] = q;\n    }\n    if\
    \ (q + 1 == n) break;\n  }\n\n  return {sa, rk};\n}\n\n// h[i] = lcp(s[sa[i]],\
    \ s[sa[i + 1]])\nstd::vector<int> calc_height(const std::string &s, const std::vector<int>\
    \ &sa,\n                             const std::vector<int> &rk)\n{\n  int n =\
    \ s.size();\n  std::vector<int> h(n);\n  int p = 0;\n  for (int i = 0; i < n;\
    \ i++) {\n    p = std::max(0, p - 1);\n    if (rk[i] + 1 == n) continue;\n   \
    \ int j = sa[rk[i] + 1];\n    int mij = std::max(i, j);\n    while (mij + p <\
    \ n && s[i + p] == s[j + p]) p++;\n    h[rk[i]] = p;\n  }\n  return h;\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <string>\n#include <utility>\n\
    \n// 0-indexed\nstd::pair<std::vector<int>, std::vector<int>> suffix_array(const\
    \ std::string &s)\n{\n  int n = s.size();\n  int m = std::max(128, n);\n\n  std::vector<int>\
    \ sa(n), rk(n), sa2(n), rk2(n * 2, -1), cnt(m + 1);\n  for (int i = 0; i < n;\
    \ i++) rk[i] = s[i];\n  for (int i = 0; i < n; i++) cnt[rk[i] + 1]++;\n  for (int\
    \ i = 1; i < m; i++) cnt[i] += cnt[i - 1];\n  for (int i = 0; i < n; i++) sa[cnt[rk[i]]++]\
    \ = i;\n\n  for (int w = 1;; w *= 2) {\n    int p = 0;\n    for (int i = n - w;\
    \ i < n; i++) sa2[p++] = i;\n    for (int i = 0; i < n; i++) {\n      if (sa[i]\
    \ >= w) sa2[p++] = sa[i] - w;\n    }\n\n    std::fill(cnt.begin(), cnt.end(),\
    \ 0);\n    for (int i = 0; i < n; i++) cnt[rk[sa2[i]] + 1]++;\n    for (int i\
    \ = 1; i < m; i++) cnt[i] += cnt[i - 1];\n    for (int i = 0; i < n; i++) sa[cnt[rk[sa2[i]]]++]\
    \ = sa2[i];\n\n    std::copy(rk.begin(), rk.end(), rk2.begin());\n    int q =\
    \ 0;\n    rk[sa[0]] = 0;\n    for (int i = 1; i < n; i++) {\n      int u = sa[i\
    \ - 1], v = sa[i];\n      if (rk2[u] != rk2[v] || rk2[u + w] != rk2[v + w]) q++;\n\
    \      rk[sa[i]] = q;\n    }\n    if (q + 1 == n) break;\n  }\n\n  return {sa,\
    \ rk};\n}\n\n// h[i] = lcp(s[sa[i]], s[sa[i + 1]])\nstd::vector<int> calc_height(const\
    \ std::string &s, const std::vector<int> &sa,\n                             const\
    \ std::vector<int> &rk)\n{\n  int n = s.size();\n  std::vector<int> h(n);\n  int\
    \ p = 0;\n  for (int i = 0; i < n; i++) {\n    p = std::max(0, p - 1);\n    if\
    \ (rk[i] + 1 == n) continue;\n    int j = sa[rk[i] + 1];\n    int mij = std::max(i,\
    \ j);\n    while (mij + p < n && s[i + p] == s[j + p]) p++;\n    h[rk[i]] = p;\n\
    \  }\n  return h;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/str/sa.hpp
  requiredBy: []
  timestamp: '2024-06-14 10:22:24+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/str/longest_common_substring.test.cpp
  - verify/str/suffixarray.test.cpp
  - verify/str/number_of_substrings.test.cpp
documentation_of: lib/str/sa.hpp
layout: document
redirect_from:
- /library/lib/str/sa.hpp
- /library/lib/str/sa.hpp.html
title: lib/str/sa.hpp
---
