---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/ds/segtree.hpp
    title: Segment Tree
  - icon: ':question:'
    path: lib/internal.hpp
    title: Internal Definition
  - icon: ':question:'
    path: lib/math/static_modint.hpp
    title: Static Modint
  - icon: ':question:'
    path: lib/misc/bitop.hpp
    title: Bit Manipulation
  - icon: ':x:'
    path: lib/monoid/monoid_trait.hpp
    title: lib/monoid/monoid_trait.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
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
  code: "#include \"lib/ds/segtree.hpp\"\n#include \"lib/math/static_modint.hpp\"\n\
    #include \"lib/monoid/monoid_trait.hpp\"\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\nstruct LinearFunc\n{\n    using mint = static_modint<998244353>;\n    mint\
    \ k, b;\n    LinearFunc(mint _k = 1, mint _b = 0): k(_k), b(_b) { }\n    LinearFunc\
    \ operator*(const LinearFunc &t) const \n    { \n        return {k * t.k, b *\
    \ t.k + t.b}; \n    }\n    mint apply(mint x) { return k * x + b; }\n};\n\nsigned\
    \ main()\n{\n    using namespace std;\n    ios::sync_with_stdio(false); cin.tie(0),\
    \ cout.tie(0);\n    auto read_int = [x = int()]() mutable { return cin >> x, x;\
    \ };\n    u32 n = read_int(), q = read_int();\n    vec<LinearFunc> a(n);\n   \
    \ for (auto &[k, b]: a) k = read_int(), b = read_int();\n    SegmentTree<mono::MonoidTrait<LinearFunc>>\
    \ s(n, [&a](u32 i){return a[i];});\n    while (q--) {\n        u32 op, x, y, z;\n\
    \        cin >> op >> x >> y >> z;\n        if (op == 0) s.set(x, {y, z});\n \
    \       else cout << s.prod(x, y).apply(z).val() << '\\n';\n    }\n}"
  dependsOn:
  - lib/ds/segtree.hpp
  - lib/internal.hpp
  - lib/misc/bitop.hpp
  - lib/monoid/monoid_trait.hpp
  - lib/math/static_modint.hpp
  isVerificationFile: true
  path: verify/ds/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2024-06-14 19:20:52+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/ds/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/verify/ds/point_set_range_composite.test.cpp
- /verify/verify/ds/point_set_range_composite.test.cpp.html
title: verify/ds/point_set_range_composite.test.cpp
---
