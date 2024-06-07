---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/internal.hpp
    title: lib/internal.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp
    title: verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/internal.hpp\"\n#include <cmath>\n#include <vector>\n\
    #include <cstring>\n#include <iostream>\n#include <algorithm>\n\nusing i32 = int;\n\
    using i64 = long long;\nusing i128 = __int128_t;\nusing u32 = unsigned int;\n\
    using u64 = unsigned long long;\nusing u128 = __uint128_t;\n\ntemplate<typename\
    \ T> using vec = std::vector<T>;\nusing pii = std::pair<int, int>;\n#line 3 \"\
    lib/ds/splay.hpp\"\n\ntemplate <typename S, typename T>\nstruct Splay\n{\n  struct\
    \ node_t\n  {\n    bool reversed;\n    u32 size;\n\n    S prod;\n    S m;\n  \
    \  T tag;\n\n    using pnode_t = node_t *;\n    pnode_t fa;\n    pnode_t ch[2];\n\
    \n    node_t() : reversed(false), size(0), prod(), m(), tag(), fa(nullptr), ch{nullptr,\
    \ nullptr} {}\n    node_t(S m) : reversed(false), size(1), prod(m), m(m), tag(),\
    \ fa(nullptr), ch{nullptr, nullptr} {}\n\n    void update()\n    {\n      size\
    \ = 1;\n      prod = m;\n      for (auto c : ch) {\n        if (!c) continue;\n\
    \        size += c->size;\n        prod = prod * c->prod;\n      }\n    }\n\n\
    \    void reverse()\n    {\n      reversed = !reversed;\n      std::swap(ch[0],\
    \ ch[1]);\n    }\n\n    void apply(const T &t)\n    {\n      prod = t(prod, size);\n\
    \      m = t(m, 1);\n      tag = tag * t;\n    }\n\n    void push()\n    {\n \
    \     for (auto c : ch) {\n        if (!c) continue;\n        if (reversed) c->reverse();\n\
    \        if (!tag.is_unit()) c->apply(tag);\n      }\n      reversed = false;\n\
    \      tag = T();\n    }\n\n    u32 which_child() const\n    {\n      return this->fa->ch[1]\
    \ == this;\n    }\n\n    void rotate()\n    {\n      auto x = this;\n\n      auto\
    \ y = x->fa;\n      auto z = y->fa;\n      auto xci = x->which_child();\n    \
    \  y->ch[xci] = x->ch[xci ^ 1];\n      if (x->ch[xci ^ 1]) x->ch[xci ^ 1]->fa\
    \ = y;\n      x->ch[xci ^ 1] = y;\n      if (z) z->ch[y->which_child()] = x;\n\
    \      y->fa = x;\n      x->fa = z;\n\n      y->update();\n      x->update();\n\
    \    }\n  };\n\n  using pnode_t = node_t *;\n  pnode_t root;\n\n  Splay() : root(nullptr)\
    \ {}\n  Splay(pnode_t root) : root(root) {}\n  template <typename F>\n    Splay(u32\
    \ n, F &&f) : root(build_tree(0, n, f, nullptr)) {}\n\n  template <typename F>\n\
    \    static pnode_t build_tree(u32 l, u32 r, F &&f, pnode_t fa)\n    {\n     \
    \ if (r - l == 0) return nullptr;\n      u32 mid = l + (r - l) / 2;\n      auto\
    \ p = new node_t(f(mid));\n      p->ch[0] = build_tree(l, mid, f, p);\n      p->ch[1]\
    \ = build_tree(mid + 1, r, f, p);\n      p->fa = fa;\n      p->update();\n   \
    \   return p;\n    }\n\n  void splay(pnode_t x)\n  {\n    x->push();\n    while\
    \ (x->fa) {\n      auto y = x->fa;\n      if (!y->fa) {\n        y->push();\n\
    \        x->push();\n        x->rotate();\n      } else {\n        auto z = y->fa;\n\
    \        z->push();\n        y->push();\n        x->push();\n        if (y->which_child()\
    \ == x->which_child()) y->rotate();\n        else x->rotate();\n        x->rotate();\n\
    \      }\n    }\n    root = x;\n  };\n\n  void splay_kth(u32 k)\n  {\n    auto\
    \ p = root;\n    while (true) {\n      auto ls = p->ch[0] ? p->ch[0]->size : 0;\n\
    \      if (k == ls) break;\n      p->push();\n      if (k < ls) {\n        p =\
    \ p->ch[0];\n      } else {\n        k -= ls + 1;\n        p = p->ch[1];\n   \
    \   }\n    }\n    splay(p);\n  }\n\n  std::pair<pnode_t, pnode_t> split(u32 k)\n\
    \  {\n    if (!root) return {nullptr, nullptr};\n    if (k == 0) return {nullptr,\
    \ root};\n    if (k == root->size) return {root, nullptr};\n    splay_kth(k);\n\
    \    auto l = root->ch[0];\n    root->ch[0] = nullptr;\n    root->update();\n\
    \    if (l) l->fa = nullptr;\n    return {l, root};\n  }\n\n  std::tuple<pnode_t,\
    \ pnode_t, pnode_t> split3(u32 l, u32 r)\n  {\n    pnode_t mp, rp;\n    std::tie(root,\
    \ rp) = split(r);\n    std::tie(root, mp) = split(l);\n    return {root, mp, rp};\n\
    \  }\n\n  static pnode_t join(pnode_t p, pnode_t q)\n  {\n    if (!p) return q;\n\
    \    if (!q) return p;\n    Splay sq = q;\n    sq.splay_kth(0);\n    q = sq.root;\n\
    \    q->ch[0] = p;\n    p->fa = q;\n    q->update();\n    return q;\n  }\n\n \
    \ static pnode_t join3(pnode_t p1, pnode_t p2, pnode_t p3)\n  {\n    return join(p1,\
    \ join(p2, p3));\n  }\n\n  void insert(u32 x, S m)\n  {\n    auto [lp, rp] = split(x);\n\
    \    root = join3(lp, new node_t(m), rp);\n  }\n\n  void remove(u32 x)\n  {\n\
    \    auto [lp, xp, rp] = split3(x, x + 1);\n    delete xp;\n    root = join(lp,\
    \ rp);\n  }\n\n  void reverse(u32 l, u32 r)\n  {\n    auto [lp, mp, rp] = split3(l,\
    \ r);\n    if (mp) mp->reverse();\n    root = join3(lp, mp, rp);\n  }\n\n  void\
    \ apply(u32 l, u32 r, T m)\n  {\n    auto [lp, mp, rp] = split3(l, r);\n    if\
    \ (mp) mp->apply(m);\n    root = join3(lp, mp, rp);\n  }\n\n  S prod(u32 l, u32\
    \ r)\n  {\n    auto [lp, mp, rp] = split3(l, r);\n    S res;\n    if (mp) res\
    \ = mp->prod;\n    root = join3(lp, mp, rp);\n    return res;\n  }\n};\n"
  code: "#pragma once\n#include \"lib/internal.hpp\"\n\ntemplate <typename S, typename\
    \ T>\nstruct Splay\n{\n  struct node_t\n  {\n    bool reversed;\n    u32 size;\n\
    \n    S prod;\n    S m;\n    T tag;\n\n    using pnode_t = node_t *;\n    pnode_t\
    \ fa;\n    pnode_t ch[2];\n\n    node_t() : reversed(false), size(0), prod(),\
    \ m(), tag(), fa(nullptr), ch{nullptr, nullptr} {}\n    node_t(S m) : reversed(false),\
    \ size(1), prod(m), m(m), tag(), fa(nullptr), ch{nullptr, nullptr} {}\n\n    void\
    \ update()\n    {\n      size = 1;\n      prod = m;\n      for (auto c : ch) {\n\
    \        if (!c) continue;\n        size += c->size;\n        prod = prod * c->prod;\n\
    \      }\n    }\n\n    void reverse()\n    {\n      reversed = !reversed;\n  \
    \    std::swap(ch[0], ch[1]);\n    }\n\n    void apply(const T &t)\n    {\n  \
    \    prod = t(prod, size);\n      m = t(m, 1);\n      tag = tag * t;\n    }\n\n\
    \    void push()\n    {\n      for (auto c : ch) {\n        if (!c) continue;\n\
    \        if (reversed) c->reverse();\n        if (!tag.is_unit()) c->apply(tag);\n\
    \      }\n      reversed = false;\n      tag = T();\n    }\n\n    u32 which_child()\
    \ const\n    {\n      return this->fa->ch[1] == this;\n    }\n\n    void rotate()\n\
    \    {\n      auto x = this;\n\n      auto y = x->fa;\n      auto z = y->fa;\n\
    \      auto xci = x->which_child();\n      y->ch[xci] = x->ch[xci ^ 1];\n    \
    \  if (x->ch[xci ^ 1]) x->ch[xci ^ 1]->fa = y;\n      x->ch[xci ^ 1] = y;\n  \
    \    if (z) z->ch[y->which_child()] = x;\n      y->fa = x;\n      x->fa = z;\n\
    \n      y->update();\n      x->update();\n    }\n  };\n\n  using pnode_t = node_t\
    \ *;\n  pnode_t root;\n\n  Splay() : root(nullptr) {}\n  Splay(pnode_t root) :\
    \ root(root) {}\n  template <typename F>\n    Splay(u32 n, F &&f) : root(build_tree(0,\
    \ n, f, nullptr)) {}\n\n  template <typename F>\n    static pnode_t build_tree(u32\
    \ l, u32 r, F &&f, pnode_t fa)\n    {\n      if (r - l == 0) return nullptr;\n\
    \      u32 mid = l + (r - l) / 2;\n      auto p = new node_t(f(mid));\n      p->ch[0]\
    \ = build_tree(l, mid, f, p);\n      p->ch[1] = build_tree(mid + 1, r, f, p);\n\
    \      p->fa = fa;\n      p->update();\n      return p;\n    }\n\n  void splay(pnode_t\
    \ x)\n  {\n    x->push();\n    while (x->fa) {\n      auto y = x->fa;\n      if\
    \ (!y->fa) {\n        y->push();\n        x->push();\n        x->rotate();\n \
    \     } else {\n        auto z = y->fa;\n        z->push();\n        y->push();\n\
    \        x->push();\n        if (y->which_child() == x->which_child()) y->rotate();\n\
    \        else x->rotate();\n        x->rotate();\n      }\n    }\n    root = x;\n\
    \  };\n\n  void splay_kth(u32 k)\n  {\n    auto p = root;\n    while (true) {\n\
    \      auto ls = p->ch[0] ? p->ch[0]->size : 0;\n      if (k == ls) break;\n \
    \     p->push();\n      if (k < ls) {\n        p = p->ch[0];\n      } else {\n\
    \        k -= ls + 1;\n        p = p->ch[1];\n      }\n    }\n    splay(p);\n\
    \  }\n\n  std::pair<pnode_t, pnode_t> split(u32 k)\n  {\n    if (!root) return\
    \ {nullptr, nullptr};\n    if (k == 0) return {nullptr, root};\n    if (k == root->size)\
    \ return {root, nullptr};\n    splay_kth(k);\n    auto l = root->ch[0];\n    root->ch[0]\
    \ = nullptr;\n    root->update();\n    if (l) l->fa = nullptr;\n    return {l,\
    \ root};\n  }\n\n  std::tuple<pnode_t, pnode_t, pnode_t> split3(u32 l, u32 r)\n\
    \  {\n    pnode_t mp, rp;\n    std::tie(root, rp) = split(r);\n    std::tie(root,\
    \ mp) = split(l);\n    return {root, mp, rp};\n  }\n\n  static pnode_t join(pnode_t\
    \ p, pnode_t q)\n  {\n    if (!p) return q;\n    if (!q) return p;\n    Splay\
    \ sq = q;\n    sq.splay_kth(0);\n    q = sq.root;\n    q->ch[0] = p;\n    p->fa\
    \ = q;\n    q->update();\n    return q;\n  }\n\n  static pnode_t join3(pnode_t\
    \ p1, pnode_t p2, pnode_t p3)\n  {\n    return join(p1, join(p2, p3));\n  }\n\n\
    \  void insert(u32 x, S m)\n  {\n    auto [lp, rp] = split(x);\n    root = join3(lp,\
    \ new node_t(m), rp);\n  }\n\n  void remove(u32 x)\n  {\n    auto [lp, xp, rp]\
    \ = split3(x, x + 1);\n    delete xp;\n    root = join(lp, rp);\n  }\n\n  void\
    \ reverse(u32 l, u32 r)\n  {\n    auto [lp, mp, rp] = split3(l, r);\n    if (mp)\
    \ mp->reverse();\n    root = join3(lp, mp, rp);\n  }\n\n  void apply(u32 l, u32\
    \ r, T m)\n  {\n    auto [lp, mp, rp] = split3(l, r);\n    if (mp) mp->apply(m);\n\
    \    root = join3(lp, mp, rp);\n  }\n\n  S prod(u32 l, u32 r)\n  {\n    auto [lp,\
    \ mp, rp] = split3(l, r);\n    S res;\n    if (mp) res = mp->prod;\n    root =\
    \ join3(lp, mp, rp);\n    return res;\n  }\n};\n"
  dependsOn:
  - lib/internal.hpp
  isVerificationFile: false
  path: lib/ds/splay.hpp
  requiredBy: []
  timestamp: '2024-06-07 18:17:19+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp
documentation_of: lib/ds/splay.hpp
layout: document
redirect_from:
- /library/lib/ds/splay.hpp
- /library/lib/ds/splay.hpp.html
title: lib/ds/splay.hpp
---
