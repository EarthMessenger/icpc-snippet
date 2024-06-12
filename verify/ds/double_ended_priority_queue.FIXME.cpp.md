---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: lib/ds/depque.hpp
    title: double ended priority queue
  - icon: ':heavy_check_mark:'
    path: lib/internal.hpp
    title: lib/internal.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
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
    \ lib/ds/depque.hpp: line 3: #pragma once found in a non-first line\n"
  code: "#include \"lib/ds/depque.hpp\"\n\nsigned main()\n{\n    using namespace std;\n\
    \    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);\n    u32 n, q;\n  \
    \  cin >> n >> q;\n    vec<int> s(n);\n    for (int &i: s) cin >> i;\n    sort(s.begin(),\
    \ s.end());\n    DEPQ<int> dq(s.begin(), s.end());\n    u32 op, x;\n    while\
    \ (q--) {\n        cin >> op;\n        if (op == 1) {\n            cout << dq.max()\
    \ << '\\n';\n            dq.pop_max();\n        }\n        else if (op == 2) {\n\
    \            cout << dq.min() << '\\n';\n            dq.pop_min();\n        }\n\
    \        else {\n            cin >> x;\n            dq.push(x);\n        }\n \
    \   }\n}"
  dependsOn:
  - lib/ds/depque.hpp
  - lib/internal.hpp
  isVerificationFile: false
  path: verify/ds/double_ended_priority_queue.FIXME.cpp
  requiredBy: []
  timestamp: '2024-06-12 11:51:09+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: verify/ds/double_ended_priority_queue.FIXME.cpp
layout: document
redirect_from:
- /library/verify/ds/double_ended_priority_queue.FIXME.cpp
- /library/verify/ds/double_ended_priority_queue.FIXME.cpp.html
title: verify/ds/double_ended_priority_queue.FIXME.cpp
---
