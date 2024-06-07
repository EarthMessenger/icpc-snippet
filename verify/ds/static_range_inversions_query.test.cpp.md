---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/internal.hpp
    title: lib/internal.hpp
  - icon: ':x:'
    path: lib/misc/mo.hpp
    title: lib/misc/mo.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"verify/ds/static_range_inversions_query.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\n\n\
    #line 2 \"lib/internal.hpp\"\n#include <cmath>\n#include <vector>\n#include <cstring>\n\
    #include <iostream>\n#include <algorithm>\n\nusing i32 = int;\nusing i64 = long\
    \ long;\nusing i128 = __int128_t;\nusing u32 = unsigned int;\nusing u64 = unsigned\
    \ long long;\nusing u128 = __uint128_t;\n\ntemplate<typename T> using vec = std::vector<T>;\n\
    using pii = std::pair<int, int>;\n#line 2 \"lib/misc/mo.hpp\"\n\n#line 4 \"lib/misc/mo.hpp\"\
    \n#include <utility>\n#line 6 \"lib/misc/mo.hpp\"\n\nstruct mo_algorithm\n{\n\
    \  std::vector<std::pair<int, int>> q;\n \n  void add_query(int l, int r)\n  {\n\
    \    q.emplace_back(l, r);\n  }\n \n  std::vector<int> sort() const\n  {\n   \
    \ int n = 0;\n    for (auto i : q) n = std::max({n, i.first, i.second});\n   \
    \ int bs = std::max(1, (int)(n / std::sqrt(q.size())));\n    std::vector<int>\
    \ ord(q.size());\n    for (int i = 0; i < (int)q.size(); i++) ord[i] = i;\n  \
    \  std::sort(ord.begin(), ord.end(),\n              [&bs, this](int x, int y)\n\
    \              {\n                int xb = q[x].first / bs, yb = q[y].first /\
    \ bs;\n                if (xb != yb) return xb < yb;\n                else if\
    \ (xb % 2 == 0) return q[x].second < q[y].second;\n                else return\
    \ q[x].second > q[y].second;\n              });\n    return ord;\n  }\n \n  template\
    \ <typename F0, typename F1, typename F2>\n  void solve(const F0 &add,\n     \
    \        const F1 &del,\n             const F2 &ans) const\n  {\n    solve(add,\
    \ add, del, del, ans);\n  }\n \n  template <typename F0, typename F1, typename\
    \ F2, typename F3, typename F4>\n  void solve(const F0 &add_l,\n             const\
    \ F1 &add_r,\n             const F2 &del_l,\n             const F3 &del_r,\n \
    \            const F4 &ans) const\n  {\n    auto ord = sort();\n    int l = 0,\
    \ r = 0;\n    for (auto i : ord) {\n      while (q[i].first < l)  add_l(--l);\n\
    \      while (r < q[i].second) add_r(r++);\n      while (l < q[i].first)  del_l(l++);\n\
    \      while (q[i].second < r) del_r(--r);\n      ans(i);\n    }\n  }\n\n  template\
    \ <typename F0, typename F1, typename F2, typename F3>\n  auto only_move(const\
    \ F0 &left_l,\n                 const F1 &right_r,\n                 const F2\
    \ &right_l,\n                 const F3 &left_r) const\n  {\n    auto ord = sort();\n\
    \    int l = 0, r = 0;\n    for (auto i : ord) {\n      if (q[i].first < l) {\n\
    \        left_l(q[i].first, l, r, i);\n        l = q[i].first;\n      }\n    \
    \  if (r < q[i].second) {\n        right_r(l, r, q[i].second, i);\n        r =\
    \ q[i].second;\n      }\n      if (l < q[i].first) {\n        right_l(l, q[i].first,\
    \ r, i);\n        l = q[i].first;\n      }\n      if (q[i].second < r) {\n   \
    \     left_r(l, q[i].second, r, i);\n        r = q[i].second;\n      }\n    }\n\
    \    return ord;\n  }\n};\n#line 5 \"verify/ds/static_range_inversions_query.test.cpp\"\
    \n\nstruct fenwicktree\n{\n  int n;\n  int all;\n  std::vector<int> f;\n  fenwicktree(int\
    \ n) : n(n), all(0), f(n) {}\n\n  void add(int x, int v)\n  {\n    all += v;\n\
    \    for (x++; x <= n; x += x & -x)\n      f[x - 1] += v;\n  }\n\n  int prod_prev(int\
    \ x) const\n  {\n    int res = 0;\n    for (; x > 0; x -= x & -x)\n      res +=\
    \ f[x - 1];\n    return res;\n  }\n\n  int prod_all() const { return all; }\n\
    };\n\nstruct SqrtDecomposition\n{\n  int n;\n  int block_size, block_cnt;\n  int\
    \ all;\n  std::vector<int> b;\n  std::vector<int> bs;\n  SqrtDecomposition(int\
    \ n)\n      : n(n), block_size((int)std::sqrt(n)),\n        block_cnt((n + block_size\
    \ - 1) / block_size), all(0), b(n + 1),\n        bs(block_cnt + 1)\n  {\n  }\n\
    \n  void add(int x, int v)\n  {\n    all += v;\n    int bx = x / block_size;\n\
    \    for (int i = x, j = x % block_size; i < n && j + 1 < block_size; i++, j++)\n\
    \      b[i + 1] += v;\n    for (int i = bx; i < block_cnt; i++)\n      bs[i +\
    \ 1] += v;\n  }\n\n  int sum(int x) const\n  {\n    int bx = x / block_size;\n\
    \    int res = bs[bx];\n    if (bx < block_cnt) res += b[x];\n    return res;\n\
    \  }\n\n  int sum_all() const { return all; }\n};\n\nint main()\n{\n  int n, m;\n\
    \  std::cin >> n >> m;\n  std::vector<int> a(n);\n  for (auto &i : a)\n    std::cin\
    \ >> i;\n  auto cc = a;\n  std::sort(cc.begin(), cc.end());\n  cc.erase(std::unique(cc.begin(),\
    \ cc.end()), cc.end());\n  for (auto &i : a)\n    i = std::lower_bound(cc.begin(),\
    \ cc.end(), i) - cc.begin();\n  int nc = cc.size();\n\n  mo_algorithm mo;\n  for\
    \ (int i = 0; i < m; i++) {\n    int l, r;\n    std::cin >> l >> r;\n    mo.add_query(l,\
    \ r);\n  }\n\n  std::vector<i64> sf(n + 1), sg(n + 1);\n  {\n    fenwicktree f(nc);\n\
    \    for (int i = 0; i < n; i++) {\n      f.add(a[i], 1);\n      sf[i + 1] = sf[i]\
    \ + f.prod_all() - f.prod_prev(a[i] + 1);\n    }\n    fenwicktree g(nc);\n   \
    \ for (int i = n; i > 0; i--) {\n      g.add(a[i - 1], 1);\n      sg[i - 1] =\
    \ sg[i] + g.prod_prev(a[i - 1]);\n    }\n  }\n\n  std::vector<i64> diff(m);\n\n\
    \  std::vector<std::vector<std::tuple<int, int, int>>> query_pl(n + 1),\n    \
    \  query_pr(n + 1), query_nl(n + 1), query_nr(n + 1);\n  auto ord = mo.only_move(\n\
    \      [&](int p, int l, int r, int i) {\n        diff[i] += sg[p] - sg[l];\n\
    \        query_nr[r].emplace_back(i, p, l);\n      },\n      [&](int l, int r,\
    \ int p, int i) {\n        diff[i] += sf[p] - sf[r];\n        query_nl[l].emplace_back(i,\
    \ r, p);\n      },\n      [&](int l, int p, int r, int i) {\n        diff[i] -=\
    \ sg[l] - sg[p];\n        query_pr[r].emplace_back(i, l, p);\n      },\n     \
    \ [&](int l, int p, int r, int i) {\n        diff[i] -= sf[r] - sf[p];\n     \
    \   query_pl[l].emplace_back(i, p, r);\n      });\n\n  {\n    SqrtDecomposition\
    \ s(nc);\n    for (int i = 0; i <= n; i++) {\n      for (auto [p, l, r] : query_pl[i])\
    \ {\n        for (int j = l; j < r; j++) {\n          diff[p] += s.sum_all() -\
    \ s.sum(a[j] + 1);\n        }\n      }\n      for (auto [p, l, r] : query_nl[i])\
    \ {\n        for (int j = l; j < r; j++) {\n          diff[p] -= s.sum_all() -\
    \ s.sum(a[j] + 1);\n        }\n      }\n      if (i < n) s.add(a[i], 1);\n   \
    \ }\n  }\n\n  {\n    SqrtDecomposition s(nc);\n    for (int i = n; i >= 0; i--)\
    \ {\n      for (auto [p, l, r] : query_pr[i]) {\n        for (int j = l; j < r;\
    \ j++) {\n          diff[p] += s.sum(a[j]);\n        }\n      }\n      for (auto\
    \ [p, l, r] : query_nr[i]) {\n        for (int j = l; j < r; j++) {\n        \
    \  diff[p] -= s.sum(a[j]);\n        }\n      }\n      if (i > 0) s.add(a[i - 1],\
    \ 1);\n    }\n  }\n\n  std::vector<i64> ans(m);\n  ans[ord[0]] = diff[ord[0]];\n\
    \  for (int i = 1; i < m; i++) {\n    int oi = ord[i], oj = ord[i - 1];\n    ans[oi]\
    \ = ans[oj] + diff[oi];\n  }\n\n  for (auto i : ans)\n    std::cout << i << \"\
    \\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include \"lib/internal.hpp\"\n#include \"lib/misc/mo.hpp\"\n\nstruct fenwicktree\n\
    {\n  int n;\n  int all;\n  std::vector<int> f;\n  fenwicktree(int n) : n(n), all(0),\
    \ f(n) {}\n\n  void add(int x, int v)\n  {\n    all += v;\n    for (x++; x <=\
    \ n; x += x & -x)\n      f[x - 1] += v;\n  }\n\n  int prod_prev(int x) const\n\
    \  {\n    int res = 0;\n    for (; x > 0; x -= x & -x)\n      res += f[x - 1];\n\
    \    return res;\n  }\n\n  int prod_all() const { return all; }\n};\n\nstruct\
    \ SqrtDecomposition\n{\n  int n;\n  int block_size, block_cnt;\n  int all;\n \
    \ std::vector<int> b;\n  std::vector<int> bs;\n  SqrtDecomposition(int n)\n  \
    \    : n(n), block_size((int)std::sqrt(n)),\n        block_cnt((n + block_size\
    \ - 1) / block_size), all(0), b(n + 1),\n        bs(block_cnt + 1)\n  {\n  }\n\
    \n  void add(int x, int v)\n  {\n    all += v;\n    int bx = x / block_size;\n\
    \    for (int i = x, j = x % block_size; i < n && j + 1 < block_size; i++, j++)\n\
    \      b[i + 1] += v;\n    for (int i = bx; i < block_cnt; i++)\n      bs[i +\
    \ 1] += v;\n  }\n\n  int sum(int x) const\n  {\n    int bx = x / block_size;\n\
    \    int res = bs[bx];\n    if (bx < block_cnt) res += b[x];\n    return res;\n\
    \  }\n\n  int sum_all() const { return all; }\n};\n\nint main()\n{\n  int n, m;\n\
    \  std::cin >> n >> m;\n  std::vector<int> a(n);\n  for (auto &i : a)\n    std::cin\
    \ >> i;\n  auto cc = a;\n  std::sort(cc.begin(), cc.end());\n  cc.erase(std::unique(cc.begin(),\
    \ cc.end()), cc.end());\n  for (auto &i : a)\n    i = std::lower_bound(cc.begin(),\
    \ cc.end(), i) - cc.begin();\n  int nc = cc.size();\n\n  mo_algorithm mo;\n  for\
    \ (int i = 0; i < m; i++) {\n    int l, r;\n    std::cin >> l >> r;\n    mo.add_query(l,\
    \ r);\n  }\n\n  std::vector<i64> sf(n + 1), sg(n + 1);\n  {\n    fenwicktree f(nc);\n\
    \    for (int i = 0; i < n; i++) {\n      f.add(a[i], 1);\n      sf[i + 1] = sf[i]\
    \ + f.prod_all() - f.prod_prev(a[i] + 1);\n    }\n    fenwicktree g(nc);\n   \
    \ for (int i = n; i > 0; i--) {\n      g.add(a[i - 1], 1);\n      sg[i - 1] =\
    \ sg[i] + g.prod_prev(a[i - 1]);\n    }\n  }\n\n  std::vector<i64> diff(m);\n\n\
    \  std::vector<std::vector<std::tuple<int, int, int>>> query_pl(n + 1),\n    \
    \  query_pr(n + 1), query_nl(n + 1), query_nr(n + 1);\n  auto ord = mo.only_move(\n\
    \      [&](int p, int l, int r, int i) {\n        diff[i] += sg[p] - sg[l];\n\
    \        query_nr[r].emplace_back(i, p, l);\n      },\n      [&](int l, int r,\
    \ int p, int i) {\n        diff[i] += sf[p] - sf[r];\n        query_nl[l].emplace_back(i,\
    \ r, p);\n      },\n      [&](int l, int p, int r, int i) {\n        diff[i] -=\
    \ sg[l] - sg[p];\n        query_pr[r].emplace_back(i, l, p);\n      },\n     \
    \ [&](int l, int p, int r, int i) {\n        diff[i] -= sf[r] - sf[p];\n     \
    \   query_pl[l].emplace_back(i, p, r);\n      });\n\n  {\n    SqrtDecomposition\
    \ s(nc);\n    for (int i = 0; i <= n; i++) {\n      for (auto [p, l, r] : query_pl[i])\
    \ {\n        for (int j = l; j < r; j++) {\n          diff[p] += s.sum_all() -\
    \ s.sum(a[j] + 1);\n        }\n      }\n      for (auto [p, l, r] : query_nl[i])\
    \ {\n        for (int j = l; j < r; j++) {\n          diff[p] -= s.sum_all() -\
    \ s.sum(a[j] + 1);\n        }\n      }\n      if (i < n) s.add(a[i], 1);\n   \
    \ }\n  }\n\n  {\n    SqrtDecomposition s(nc);\n    for (int i = n; i >= 0; i--)\
    \ {\n      for (auto [p, l, r] : query_pr[i]) {\n        for (int j = l; j < r;\
    \ j++) {\n          diff[p] += s.sum(a[j]);\n        }\n      }\n      for (auto\
    \ [p, l, r] : query_nr[i]) {\n        for (int j = l; j < r; j++) {\n        \
    \  diff[p] -= s.sum(a[j]);\n        }\n      }\n      if (i > 0) s.add(a[i - 1],\
    \ 1);\n    }\n  }\n\n  std::vector<i64> ans(m);\n  ans[ord[0]] = diff[ord[0]];\n\
    \  for (int i = 1; i < m; i++) {\n    int oi = ord[i], oj = ord[i - 1];\n    ans[oi]\
    \ = ans[oj] + diff[oi];\n  }\n\n  for (auto i : ans)\n    std::cout << i << \"\
    \\n\";\n}\n"
  dependsOn:
  - lib/internal.hpp
  - lib/misc/mo.hpp
  isVerificationFile: true
  path: verify/ds/static_range_inversions_query.test.cpp
  requiredBy: []
  timestamp: '2024-06-07 20:51:56+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/ds/static_range_inversions_query.test.cpp
layout: document
redirect_from:
- /verify/verify/ds/static_range_inversions_query.test.cpp
- /verify/verify/ds/static_range_inversions_query.test.cpp.html
title: verify/ds/static_range_inversions_query.test.cpp
---
