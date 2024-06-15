---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/ds/segtree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: lib/internal.hpp
    title: Internal Definition
  - icon: ':heavy_check_mark:'
    path: lib/misc/bitop.hpp
    title: Bit Manipulation
  - icon: ':heavy_check_mark:'
    path: lib/monoid/monoid_add.hpp
    title: lib/monoid/monoid_add.hpp
  - icon: ':heavy_check_mark:'
    path: lib/monoid/monoid_trait.hpp
    title: lib/monoid/monoid_trait.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ lib/internal.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#include \"lib/ds/segtree.hpp\"\n#include \"lib/monoid/monoid_add.hpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\nsigned\
    \ main()\n{\n    using namespace std;\n    ios::sync_with_stdio(false); cin.tie(0),\
    \ cout.tie(0);\n    u32 n, q;\n    cin >> n >> q;\n    vec<i64> a(n);\n    for\
    \ (auto &i: a) cin >> i;\n    SegmentTree<mono::MonoidAdd<i64>> s(n, [&a](u32\
    \ i){return a[i];});\n    long long op, x, y;\n    while (q--) {\n        cin\
    \ >> op >> x >> y;\n        if (op == 0) s.set(x, a[x] += y);\n        else cout\
    \ << s.prod(x, y) << '\\n';\n    }\n}"
  dependsOn:
  - lib/ds/segtree.hpp
  - lib/internal.hpp
  - lib/misc/bitop.hpp
  - lib/monoid/monoid_trait.hpp
  - lib/monoid/monoid_add.hpp
  isVerificationFile: true
  path: verify/ds/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-06-15 17:22:49+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/ds/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/ds/point_add_range_sum.test.cpp
- /verify/verify/ds/point_add_range_sum.test.cpp.html
title: verify/ds/point_add_range_sum.test.cpp
---
