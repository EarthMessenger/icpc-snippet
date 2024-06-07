---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/ds/splay.hpp
    title: lib/ds/splay.hpp
  - icon: ':heavy_check_mark:'
    path: lib/internal.hpp
    title: lib/internal.hpp
  - icon: ':heavy_check_mark:'
    path: lib/math/static_modint.hpp
    title: lib/math/static_modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
  bundledCode: "#line 1 \"verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp\"\
    \n#define PROBLEM                                                            \
    \    \\\n  \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <string>\n#include <tuple>\n\
    #include <vector>\n\nusing i64 = long long;\nusing i128 = __int128_t;\nusing u32\
    \ = unsigned int;\nusing u64 = unsigned long long;\nusing u128 = __uint128_t;\n\
    \n#line 2 \"lib/internal.hpp\"\n#include <cmath>\n#line 4 \"lib/internal.hpp\"\
    \n#include <cstring>\n#line 7 \"lib/internal.hpp\"\n\nusing i32 = int;\nusing\
    \ i64 = long long;\nusing i128 = __int128_t;\nusing u32 = unsigned int;\nusing\
    \ u64 = unsigned long long;\nusing u128 = __uint128_t;\n\ntemplate<typename T>\
    \ using vec = std::vector<T>;\nusing pii = std::pair<int, int>;\n#line 3 \"lib/ds/splay.hpp\"\
    \n\ntemplate <typename S, typename T>\nstruct Splay\n{\n  struct node_t\n  {\n\
    \    bool reversed;\n    u32 size;\n\n    S prod;\n    S m;\n    T tag;\n\n  \
    \  using pnode_t = node_t *;\n    pnode_t fa;\n    pnode_t ch[2];\n\n    node_t()\
    \ : reversed(false), size(0), prod(), m(), tag(), fa(nullptr), ch{nullptr, nullptr}\
    \ {}\n    node_t(S m) : reversed(false), size(1), prod(m), m(m), tag(), fa(nullptr),\
    \ ch{nullptr, nullptr} {}\n\n    void update()\n    {\n      size = 1;\n     \
    \ prod = m;\n      for (auto c : ch) {\n        if (!c) continue;\n        size\
    \ += c->size;\n        prod = prod * c->prod;\n      }\n    }\n\n    void reverse()\n\
    \    {\n      reversed = !reversed;\n      std::swap(ch[0], ch[1]);\n    }\n\n\
    \    void apply(const T &t)\n    {\n      prod = t(prod, size);\n      m = t(m,\
    \ 1);\n      tag = tag * t;\n    }\n\n    void push()\n    {\n      for (auto\
    \ c : ch) {\n        if (!c) continue;\n        if (reversed) c->reverse();\n\
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
    \ = mp->prod;\n    root = join3(lp, mp, rp);\n    return res;\n  }\n};\n#line\
    \ 3 \"lib/math/static_modint.hpp\"\n\ntemplate <int M>\nstruct static_modint\n\
    {\n  static constexpr u32 UM = M;\n  static_assert(UM < 0x80'00'00'00u);\n\n \
    \ u32 v;\n  constexpr static_modint() : v(0) {}\n\n  template <typename T, std::enable_if_t<std::is_signed_v<T>>*\
    \ = nullptr>\n  constexpr static_modint(T n) : v((n %= M) < 0 ? n + M : n) {}\n\
    \n  template <typename T, std::enable_if_t<std::is_unsigned_v<T>>* = nullptr>\n\
    \  constexpr static_modint(T n) : v(n %= UM) {}\n\n  using mint = static_modint;\n\
    \n  static mint raw(u32 v)\n  {\n    mint res;\n    res.v = v;\n    return res;\n\
    \  }\n\n  constexpr u32 val() const { return v; }\n\n  mint operator-() const\
    \ { return mint::raw(v == 0 ? 0u : UM - v); }\n\n  mint &operator+=(mint a)\n\
    \  {\n    if ((v += a.v) >= UM) v -= UM;\n    return *this;\n  }\n  mint &operator-=(mint\
    \ a)\n  {\n    if ((v += UM - a.v) >= UM) v -= UM;\n    return *this;\n  }\n \
    \ mint &operator*=(mint a)\n  {\n    v = (u64)v * a.v % UM;\n    return *this;\n\
    \  }\n  mint &operator/=(mint a) { return *this *= a.inv(); }\n\n  friend mint\
    \ operator+(mint a, mint b) { return a += b; }\n  friend mint operator-(mint a,\
    \ mint b) { return a -= b; }\n  friend mint operator*(mint a, mint b) { return\
    \ a *= b; }\n  friend mint operator/(mint a, mint b) { return a /= b; }\n\n  mint\
    \ pow(u64 n) const\n  {\n    mint res = 1, base = *this;\n    while (n) {\n  \
    \    if (n & 1) res *= base;\n      base *= base;\n      n >>= 1;\n    }\n   \
    \ return res;\n  }\n\n  mint inv() const { return pow(UM - 2); }\n};\n#line 18\
    \ \"verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp\"\n\nusing\
    \ mint = static_modint<998'244'353>;\n\nstruct SumMonoid\n{\n  mint sum;\n  SumMonoid()\
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
  code: "#define PROBLEM                                                         \
    \       \\\n  \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <string>\n#include <tuple>\n\
    #include <vector>\n\nusing i64 = long long;\nusing i128 = __int128_t;\nusing u32\
    \ = unsigned int;\nusing u64 = unsigned long long;\nusing u128 = __uint128_t;\n\
    \n#include \"lib/ds/splay.hpp\"\n#include \"lib/math/static_modint.hpp\"\n\nusing\
    \ mint = static_modint<998'244'353>;\n\nstruct SumMonoid\n{\n  mint sum;\n  SumMonoid()\
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
  dependsOn:
  - lib/ds/splay.hpp
  - lib/internal.hpp
  - lib/math/static_modint.hpp
  isVerificationFile: true
  path: verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  requiredBy: []
  timestamp: '2024-06-07 18:17:19+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp
layout: document
redirect_from:
- /verify/verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp
- /verify/verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp.html
title: verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp
---
