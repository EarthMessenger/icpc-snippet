---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/internal.hpp
    title: Internal Definition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ lib/internal.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#pragma once\n#include \"lib/internal.hpp\"\n#include <array>\n\ntemplate<typename\
    \ S, typename F, int id = 0>\nclass DynamicSegmentTree\n{\npublic:\n    const\
    \ S e;\n    const F op;\n\n    struct Node\n    {\n        S val;\n        u32\
    \ ls, rs;\n        Node(S v): val(v), ls(), rs() { }\n    };\n\n    u32 n, root;\n\
    \    static vec<Node> t;\n\n    DynamicSegmentTree(u32 _n, const S &_e, const\
    \ F &_op): n(_n), e(_e), op(_op) { }\n\n    void update(u32 x) { t[x].val = op(t[t[x].ls].val,\
    \ t[t[x].rs].val); }\n\n    static u32 new_node() \n    {\n        t.emplace_back(e);\n\
    \        return t.size() - 1u;\n    }\n\n    void set(u32 x, const S &v)\n   \
    \ {\n        if (x == 0) x = new_node();\n    }\n\nprivate:\n\n    void set_rec(const\
    \ S &v, u32 l, u32 r, u32 x)\n    {\n        if (x == 0) x = new_node();\n   \
    \ }\n};"
  dependsOn:
  - lib/internal.hpp
  isVerificationFile: false
  path: lib/ds/dyn_segtree.hpp
  requiredBy: []
  timestamp: '2024-06-14 09:23:51+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/ds/dyn_segtree.hpp
layout: document
redirect_from:
- /library/lib/ds/dyn_segtree.hpp
- /library/lib/ds/dyn_segtree.hpp.html
title: lib/ds/dyn_segtree.hpp
---
