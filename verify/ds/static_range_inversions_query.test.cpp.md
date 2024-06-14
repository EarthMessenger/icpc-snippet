---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/internal.hpp
    title: Internal Definition
  - icon: ':heavy_check_mark:'
    path: lib/misc/mo.hpp
    title: Mo's Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ lib/internal.hpp: line 4: #pragma once found in a non-first line\n"
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
  timestamp: '2024-06-14 09:23:51+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/ds/static_range_inversions_query.test.cpp
layout: document
redirect_from:
- /verify/verify/ds/static_range_inversions_query.test.cpp
- /verify/verify/ds/static_range_inversions_query.test.cpp.html
title: verify/ds/static_range_inversions_query.test.cpp
---
