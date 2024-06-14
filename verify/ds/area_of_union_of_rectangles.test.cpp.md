---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/ds/lazysegtree.hpp
    title: lib/ds/lazysegtree.hpp
  - icon: ':question:'
    path: lib/internal.hpp
    title: Internal Definition
  - icon: ':heavy_check_mark:'
    path: lib/misc/bitop.hpp
    title: Bit Manipulation
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/area_of_union_of_rectangles
    links:
    - https://judge.yosupo.jp/problem/area_of_union_of_rectangles
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/area_of_union_of_rectangles\"\
    \n\n#include \"lib/ds/lazysegtree.hpp\"\n\n#include <limits>\n\nconstexpr int\
    \ INF = std::numeric_limits<int>::max() / 2;\n\nstruct MinCnt\n{\n  using MS =\
    \ MinCnt;\n  struct S\n  {\n    int min, cnt;\n    S() : min(INF), cnt(0) {}\n\
    \    S(int min, int cnt) : min(min), cnt(cnt) {}\n  };\n\n  static S op(S x, S\
    \ y)\n  {\n    if (x.min > y.min) return y;\n    else if (x.min < y.min) return\
    \ x;\n    return {x.min, x.cnt + y.cnt};\n  }\n  static S un() { return S{}; }\n\
    \n  static constexpr bool cm = true;\n};\n\nstruct Add\n{\n  using MS = Add;\n\
    \  using S = int;\n\n  static S op(S x, S y) { return x + y; }\n  static S un()\
    \ { return 0; }\n};\n\nstruct Monoid\n{\n  using MS = MinCnt;\n  using MA = Add;\n\
    \  using S = MS::S;\n  using A = MA::S;\n  static S act(A a, S s, u32)\n  {\n\
    \    return {s.min + a, s.cnt};\n  }\n};\n\nstruct sweepline_t\n{\n  int x, l,\
    \ r, v;\n  sweepline_t(int x, int l, int r, int v) :\n    x(x), l(l), r(r), v(v)\
    \ {}\n  bool operator<(const sweepline_t &sl) const\n  {\n    return x < sl.x;\n\
    \  }\n};\n\nint main()\n{\n  int N;\n  std::cin >> N;\n\n  std::vector<sweepline_t>\
    \ sweeplines;\n  std::vector<int> cc;\n\n  for (int i = 0; i < N; i++) {\n   \
    \ int x1, y1, x2, y2;\n    std::cin >> x1 >> y1 >> x2 >> y2;\n    cc.emplace_back(y1);\n\
    \    cc.emplace_back(y2);\n    sweeplines.emplace_back(x1, y1, y2, 1);\n    sweeplines.emplace_back(x2,\
    \ y1, y2, -1);\n  }\n\n  std::sort(cc.begin(), cc.end());\n  cc.erase(std::unique(cc.begin(),\
    \ cc.end()), cc.end());\n  auto val = [&](int x)\n  {\n    return std::lower_bound(cc.begin(),\
    \ cc.end(), x) - cc.begin();\n  };\n\n  std::sort(sweeplines.begin(), sweeplines.end());\n\
    \n  LazySegtree<Monoid> s(cc.size() - 1,\n                        [&](u32 x)\n\
    \                        {\n                          return MinCnt::S(0, cc[x\
    \ + 1] - cc[x]);\n                        });\n\n  int tot = cc.back() - cc[0];\n\
    \n  int m = sweeplines.size();\n  i64 ans = 0;\n  for (int i = 0; i + 1 < m; i++)\
    \ {\n    const auto &si = sweeplines[i];\n    s.apply(val(si.l), val(si.r), si.v);\n\
    \    int x = sweeplines[i + 1].x - si.x;\n    if (x) {\n      auto all = s.prod_all();\n\
    \      if (all.min == 0) ans += (i64)x * (tot - all.cnt);\n      else ans += (i64)x\
    \ * tot;\n    }\n  }\n\n  std::cout << ans << std::endl;\n}\n"
  dependsOn:
  - lib/ds/lazysegtree.hpp
  - lib/internal.hpp
  - lib/misc/bitop.hpp
  isVerificationFile: true
  path: verify/ds/area_of_union_of_rectangles.test.cpp
  requiredBy: []
  timestamp: '2024-06-14 21:22:57+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/ds/area_of_union_of_rectangles.test.cpp
layout: document
redirect_from:
- /verify/verify/ds/area_of_union_of_rectangles.test.cpp
- /verify/verify/ds/area_of_union_of_rectangles.test.cpp.html
title: verify/ds/area_of_union_of_rectangles.test.cpp
---
