---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
  timestamp: '2024-06-14 09:23:51+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/str/kmp.hpp
layout: document
redirect_from:
- /library/lib/str/kmp.hpp
- /library/lib/str/kmp.hpp.html
title: lib/str/kmp.hpp
---
