---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/splay.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM                                                         \
    \       \\\n  \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <string>\n#include <tuple>\n\
    #include <vector>\n\nusing i64 = long long;\nusing i128 = __int128_t;\nusing u32\
    \ = unsigned int;\nusing u64 = unsigned long long;\nusing u128 = __uint128_t;\n\
    \n#include \"ds/splay.hpp\"\n#include \"math/static_modint.hpp\"\n\nusing mint\
    \ = static_modint<998'244'353>;\n\nstruct SumMonoid\n{\n  mint sum;\n  SumMonoid()\
    \ : sum(0) {}\n  SumMonoid(mint sum) : sum(sum) {}\n\n  SumMonoid operator*(const\
    \ SumMonoid &s) const { return sum + s.sum; };\n};\n\nstruct AddTimesMonoid\n\
    {\n  mint k, b;\n  AddTimesMonoid() : k(1), b(0) {}\n  AddTimesMonoid(mint k,\
    \ mint b) : k(k), b(b) {}\n\n  AddTimesMonoid operator*(const AddTimesMonoid &a)\
    \ const\n  {\n    return {k * a.k, b * a.k + a.b};\n  };\n\n  SumMonoid operator()(const\
    \ SumMonoid &s, u32 size) const\n  {\n    return {s.sum * k + b * size};\n  }\n\
    \n  bool is_unit() const { return k.val() == 1 && b.val() == 0; }\n};\n\nint main()\n\
    {\n  std::ios::sync_with_stdio(false);\n  std::cin.tie(nullptr);\n\n  int n, Q;\n\
    \  std::cin >> n >> Q;\n  std::vector<mint> a(n);\n  for (auto &i : a) {\n   \
    \ int v;\n    std::cin >> v;\n    i = v;\n  }\n\n  Splay<SumMonoid, AddTimesMonoid>\
    \ t(n, [&a](u32 x) { return a[x]; });\n\n  for (int i = 0; i < Q; i++) {\n   \
    \ int op;\n    std::cin >> op;\n    if (op == 0) {\n      int i, x;\n      std::cin\
    \ >> i >> x;\n      t.insert(i, SumMonoid(x));\n    } else if (op == 1) {\n  \
    \    int i;\n      std::cin >> i;\n      t.remove(i);\n    } else if (op == 2)\
    \ {\n      int l, r;\n      std::cin >> l >> r;\n      t.reverse(l, r);\n    }\
    \ else if (op == 3) {\n      int l, r, b, c;\n      std::cin >> l >> r >> b >>\
    \ c;\n      t.apply(l, r, AddTimesMonoid(b, c));\n    } else if (op == 4) {\n\
    \      int l, r;\n      std::cin >> l >> r;\n      std::cout << t.prod(l, r).sum.val()\
    \ << \"\\n\";\n    }\n  }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp
layout: document
redirect_from:
- /verify/verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp
- /verify/verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp.html
title: verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp
---
