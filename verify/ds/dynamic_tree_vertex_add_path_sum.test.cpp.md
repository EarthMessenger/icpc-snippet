---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/ds/lct.hpp
    title: lib/ds/lct.hpp
  - icon: ':heavy_check_mark:'
    path: lib/internal.hpp
    title: lib/internal.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum
  bundledCode: "#line 1 \"verify/ds/dynamic_tree_vertex_add_path_sum.test.cpp\"\n\
    #define PROBLEM                                                              \
    \  \\\n  \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum\"\n\
    \n#line 2 \"lib/internal.hpp\"\n#include <cmath>\n#include <vector>\n#include\
    \ <cstring>\n#include <iostream>\n#include <algorithm>\n\nusing i32 = int;\nusing\
    \ i64 = long long;\nusing i128 = __int128_t;\nusing u32 = unsigned int;\nusing\
    \ u64 = unsigned long long;\nusing u128 = __uint128_t;\n\ntemplate<typename T>\
    \ using vec = std::vector<T>;\nusing pii = std::pair<int, int>;\n#line 3 \"lib/ds/lct.hpp\"\
    \n\ntemplate <typename T>\nstruct LinkCutTree\n{\n  struct Splay\n  {\n    using\
    \ ptr = Splay *;\n\n    u32 size;\n    bool reversed;\n    T val, prod;\n    ptr\
    \ fa, ch[2];\n\n    Splay() : size(0), reversed(false), val(), prod(), fa(nullptr),\
    \ ch{nullptr, nullptr} {}\n    Splay(const T &val) : size(1), reversed(false),\
    \ val(val), prod(val), fa(nullptr), ch{nullptr, nullptr} {}\n\n    void update()\n\
    \    {\n      size = 1;\n      prod = val;\n      for (auto c : ch) {\n      \
    \  if (!c) continue;\n        size += c->size;\n        prod = prod * c->prod;\n\
    \      }\n    }\n\n    void reverse()\n    {\n      reversed = !reversed;\n  \
    \    std::swap(ch[0], ch[1]);\n    }\n\n    void set(const T &v)\n    {\n    \
    \  val = v;\n      update();\n    }\n\n    void push()\n    {\n      for (auto\
    \ c : ch) {\n        if (!c) continue;\n        if (reversed) c->reverse();\n\
    \      }\n      reversed = false;\n    }\n\n    u32 which_child() const\n    {\n\
    \      return fa->ch[1] == this;\n    }\n\n    bool is_root() const\n    {\n \
    \     return fa == nullptr || (fa->ch[0] != this && fa->ch[1] != this);\n    }\n\
    \n    void rotate()\n    {\n      auto x = this;\n\n      auto y = x->fa;\n  \
    \    auto z = y->fa;\n      auto xci = which_child();\n      y->ch[xci] = x->ch[xci\
    \ ^ 1];\n      if (x->ch[xci ^ 1]) x->ch[xci ^ 1]->fa = y;\n      x->ch[xci ^\
    \ 1] = y;\n      if (!y->is_root()) z->ch[y->which_child()] = x;\n      y->fa\
    \ = x;\n      x->fa = z;\n\n      y->update();\n      x->update();\n    }\n\n\
    \    void splay()\n    {\n      push();\n      while (!is_root()) {\n        auto\
    \ y = fa;\n        if (y->is_root()) {\n          y->push();\n          push();\n\
    \          rotate();\n        } else {\n          auto z = y->fa;\n          z->push();\n\
    \          y->push();\n          push();\n          if (y->which_child() == which_child())\
    \ y->rotate();\n          else rotate();\n          rotate();\n        }\n   \
    \   }\n    }\n\n    ptr access()\n    {\n      ptr rp = nullptr;\n      ptr cur\
    \ = this;\n      while (cur) {\n        cur->splay();\n        cur->ch[1] = rp;\n\
    \        cur->update();\n        rp = cur;\n        cur = cur->fa;\n      }\n\
    \      splay();\n      return rp;\n    }\n\n    void make_root()\n    {\n    \
    \  access();\n      reverse();\n    }\n  };\n\n  using ptr = typename Splay::ptr;\n\
    \n  std::vector<ptr> ptrs;\n\n  template <typename F>\n    LinkCutTree(int n,\
    \ F &&f) : ptrs(n)\n  {\n    for (int i = 0; i < n; i++) ptrs[i] = new Splay(f(i));\n\
    \  }\n\n  void link(int x, int y)\n  {\n    auto xp = ptrs[x], yp = ptrs[y];\n\
    \    xp->make_root();\n    xp->fa = yp;\n  }\n\n  void cut(int x, int y)\n  {\n\
    \    auto xp = ptrs[x], yp = ptrs[y];\n    xp->make_root();\n    yp->access();\n\
    \    yp->ch[0] = xp->fa = nullptr;\n  }\n\n  T prod(int x, int y)\n  {\n    auto\
    \ xp = ptrs[x], yp = ptrs[y];\n    xp->make_root();\n    yp->access();\n    return\
    \ yp->prod;\n  }\n\n  void set(int x, const T &v)\n  {\n    auto xp = ptrs[x];\n\
    \    xp->splay();\n    xp->set(v);\n  }\n\n  void multiply(int x, const T &v)\n\
    \  {\n    auto xp = ptrs[x];\n    xp->splay();\n    xp->set(xp->val * v);\n  }\n\
    \n  T get(int x)\n  {\n    return ptrs[x]->val;\n  }\n};\n#line 6 \"verify/ds/dynamic_tree_vertex_add_path_sum.test.cpp\"\
    \n\nstruct SumMonoid\n{\n  i64 s;\n  SumMonoid() : s(0) {}\n  SumMonoid(i64 s)\
    \ : s(s) {}\n  friend SumMonoid operator*(SumMonoid a, SumMonoid b) { return a.s\
    \ + b.s; }\n};\n\nint main()\n{\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \  std::clog << std::boolalpha;\n\n  int n, q;\n  std::cin >> n >> q;\n\n  std::vector<int>\
    \ a(n);\n  for (int i = 0; i < n; i++)\n    std::cin >> a[i];\n\n  LinkCutTree<SumMonoid>\
    \ lct(n, [&a](int x) { return SumMonoid(a[x]); });\n  for (int i = 1; i < n; i++)\
    \ {\n    int u, v;\n    std::cin >> u >> v;\n    lct.link(u, v);\n  }\n\n  for\
    \ (int i = 0; i < q; i++) {\n    int op;\n    std::cin >> op;\n    if (op == 0)\
    \ {\n      int u, v, w, x;\n      std::cin >> u >> v >> w >> x;\n      lct.cut(u,\
    \ v);\n      lct.link(w, x);\n    } else if (op == 1) {\n      int p, x;\n   \
    \   std::cin >> p >> x;\n      lct.multiply(p, x);\n    } else if (op == 2) {\n\
    \      int u, v;\n      std::cin >> u >> v;\n      std::cout << lct.prod(u, v).s\
    \ << \"\\n\";\n    }\n  }\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\n  \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum\"\
    \n\n#include \"lib/ds/lct.hpp\"\n#include \"lib/internal.hpp\"\n\nstruct SumMonoid\n\
    {\n  i64 s;\n  SumMonoid() : s(0) {}\n  SumMonoid(i64 s) : s(s) {}\n  friend SumMonoid\
    \ operator*(SumMonoid a, SumMonoid b) { return a.s + b.s; }\n};\n\nint main()\n\
    {\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n  std::clog\
    \ << std::boolalpha;\n\n  int n, q;\n  std::cin >> n >> q;\n\n  std::vector<int>\
    \ a(n);\n  for (int i = 0; i < n; i++)\n    std::cin >> a[i];\n\n  LinkCutTree<SumMonoid>\
    \ lct(n, [&a](int x) { return SumMonoid(a[x]); });\n  for (int i = 1; i < n; i++)\
    \ {\n    int u, v;\n    std::cin >> u >> v;\n    lct.link(u, v);\n  }\n\n  for\
    \ (int i = 0; i < q; i++) {\n    int op;\n    std::cin >> op;\n    if (op == 0)\
    \ {\n      int u, v, w, x;\n      std::cin >> u >> v >> w >> x;\n      lct.cut(u,\
    \ v);\n      lct.link(w, x);\n    } else if (op == 1) {\n      int p, x;\n   \
    \   std::cin >> p >> x;\n      lct.multiply(p, x);\n    } else if (op == 2) {\n\
    \      int u, v;\n      std::cin >> u >> v;\n      std::cout << lct.prod(u, v).s\
    \ << \"\\n\";\n    }\n  }\n}\n"
  dependsOn:
  - lib/ds/lct.hpp
  - lib/internal.hpp
  isVerificationFile: true
  path: verify/ds/dynamic_tree_vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2024-06-07 18:17:19+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/ds/dynamic_tree_vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/ds/dynamic_tree_vertex_add_path_sum.test.cpp
- /verify/verify/ds/dynamic_tree_vertex_add_path_sum.test.cpp.html
title: verify/ds/dynamic_tree_vertex_add_path_sum.test.cpp
---
