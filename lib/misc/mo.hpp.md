---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/ds/static_range_inversions_query.test.cpp
    title: verify/ds/static_range_inversions_query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/misc/mo.hpp\"\n\n#include <algorithm>\n#include <utility>\n\
    #include <vector>\n\nstruct mo_algorithm\n{\n  std::vector<std::pair<int, int>>\
    \ q;\n\n  void add_query(int l, int r) { q.emplace_back(l, r); }\n\n  std::vector<int>\
    \ sort() const\n  {\n    int n = 0;\n    for (auto i : q) n = std::max({n, i.first,\
    \ i.second});\n    int bs = std::max(1, (int)(n / std::sqrt(q.size())));\n   \
    \ std::vector<int> ord(q.size());\n    for (int i = 0; i < (int)q.size(); i++)\
    \ ord[i] = i;\n    std::sort(ord.begin(), ord.end(), [&bs, this](int x, int y)\
    \ {\n      int xb = q[x].first / bs, yb = q[y].first / bs;\n      if (xb != yb)\
    \ return xb < yb;\n      else if (xb % 2 == 0) return q[x].second < q[y].second;\n\
    \      else return q[x].second > q[y].second;\n    });\n    return ord;\n  }\n\
    \n  template <typename F0, typename F1, typename F2>\n  void solve(const F0 &add,\
    \ const F1 &del, const F2 &ans) const\n  {\n    solve(add, add, del, del, ans);\n\
    \  }\n\n  template <typename F0, typename F1, typename F2, typename F3, typename\
    \ F4>\n  void solve(const F0 &add_l, const F1 &add_r, const F2 &del_l, const F3\
    \ &del_r,\n             const F4 &ans) const\n  {\n    auto ord = sort();\n  \
    \  int l = 0, r = 0;\n    for (auto i : ord) {\n      while (q[i].first < l) add_l(--l);\n\
    \      while (r < q[i].second) add_r(r++);\n      while (l < q[i].first) del_l(l++);\n\
    \      while (q[i].second < r) del_r(--r);\n      ans(i);\n    }\n  }\n\n  template\
    \ <typename F0, typename F1, typename F2, typename F3>\n  auto only_move(const\
    \ F0 &left_l, const F1 &right_r, const F2 &right_l,\n                 const F3\
    \ &left_r) const\n  {\n    auto ord = sort();\n    int l = 0, r = 0;\n    for\
    \ (auto i : ord) {\n      if (q[i].first < l) {\n        left_l(q[i].first, l,\
    \ r, i);\n        l = q[i].first;\n      }\n      if (r < q[i].second) {\n   \
    \     right_r(l, r, q[i].second, i);\n        r = q[i].second;\n      }\n    \
    \  if (l < q[i].first) {\n        right_l(l, q[i].first, r, i);\n        l = q[i].first;\n\
    \      }\n      if (q[i].second < r) {\n        left_r(l, q[i].second, r, i);\n\
    \        r = q[i].second;\n      }\n    }\n    return ord;\n  }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <utility>\n#include <vector>\n\
    \nstruct mo_algorithm\n{\n  std::vector<std::pair<int, int>> q;\n\n  void add_query(int\
    \ l, int r) { q.emplace_back(l, r); }\n\n  std::vector<int> sort() const\n  {\n\
    \    int n = 0;\n    for (auto i : q) n = std::max({n, i.first, i.second});\n\
    \    int bs = std::max(1, (int)(n / std::sqrt(q.size())));\n    std::vector<int>\
    \ ord(q.size());\n    for (int i = 0; i < (int)q.size(); i++) ord[i] = i;\n  \
    \  std::sort(ord.begin(), ord.end(), [&bs, this](int x, int y) {\n      int xb\
    \ = q[x].first / bs, yb = q[y].first / bs;\n      if (xb != yb) return xb < yb;\n\
    \      else if (xb % 2 == 0) return q[x].second < q[y].second;\n      else return\
    \ q[x].second > q[y].second;\n    });\n    return ord;\n  }\n\n  template <typename\
    \ F0, typename F1, typename F2>\n  void solve(const F0 &add, const F1 &del, const\
    \ F2 &ans) const\n  {\n    solve(add, add, del, del, ans);\n  }\n\n  template\
    \ <typename F0, typename F1, typename F2, typename F3, typename F4>\n  void solve(const\
    \ F0 &add_l, const F1 &add_r, const F2 &del_l, const F3 &del_r,\n            \
    \ const F4 &ans) const\n  {\n    auto ord = sort();\n    int l = 0, r = 0;\n \
    \   for (auto i : ord) {\n      while (q[i].first < l) add_l(--l);\n      while\
    \ (r < q[i].second) add_r(r++);\n      while (l < q[i].first) del_l(l++);\n  \
    \    while (q[i].second < r) del_r(--r);\n      ans(i);\n    }\n  }\n\n  template\
    \ <typename F0, typename F1, typename F2, typename F3>\n  auto only_move(const\
    \ F0 &left_l, const F1 &right_r, const F2 &right_l,\n                 const F3\
    \ &left_r) const\n  {\n    auto ord = sort();\n    int l = 0, r = 0;\n    for\
    \ (auto i : ord) {\n      if (q[i].first < l) {\n        left_l(q[i].first, l,\
    \ r, i);\n        l = q[i].first;\n      }\n      if (r < q[i].second) {\n   \
    \     right_r(l, r, q[i].second, i);\n        r = q[i].second;\n      }\n    \
    \  if (l < q[i].first) {\n        right_l(l, q[i].first, r, i);\n        l = q[i].first;\n\
    \      }\n      if (q[i].second < r) {\n        left_r(l, q[i].second, r, i);\n\
    \        r = q[i].second;\n      }\n    }\n    return ord;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/misc/mo.hpp
  requiredBy: []
  timestamp: '2024-06-12 11:51:09+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/ds/static_range_inversions_query.test.cpp
documentation_of: lib/misc/mo.hpp
layout: document
redirect_from:
- /library/lib/misc/mo.hpp
- /library/lib/misc/mo.hpp.html
title: lib/misc/mo.hpp
---
