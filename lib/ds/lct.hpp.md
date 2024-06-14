---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/internal.hpp
    title: Internal Definition
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/ds/dynamic_tree_vertex_add_path_sum.test.cpp
    title: verify/ds/dynamic_tree_vertex_add_path_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Link Cut Tree
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
  code: "#pragma once\n#include \"lib/internal.hpp\"\n\n/**\n * @brief Link Cut Tree\n\
    \ *\n * @tparam T typename\n */\ntemplate <typename T> struct LinkCutTree\n{\n\
    \  struct Splay\n  {\n    using ptr = Splay *;\n\n    u32 size;\n    bool reversed;\n\
    \    T val, prod;\n    ptr fa, ch[2];\n\n    Splay()\n        : size(0), reversed(false),\
    \ val(), prod(), fa(nullptr),\n          ch{nullptr, nullptr}\n    {\n    }\n\
    \    Splay(const T &val)\n        : size(1), reversed(false), val(val), prod(val),\
    \ fa(nullptr),\n          ch{nullptr, nullptr}\n    {\n    }\n\n    void update()\n\
    \    {\n      size = 1;\n      prod = val;\n      for (auto c : ch) {\n      \
    \  if (!c) continue;\n        size += c->size;\n        prod = prod * c->prod;\n\
    \      }\n    }\n\n    void reverse()\n    {\n      reversed = !reversed;\n  \
    \    std::swap(ch[0], ch[1]);\n    }\n\n    void set(const T &v)\n    {\n    \
    \  val = v;\n      update();\n    }\n\n    void push()\n    {\n      for (auto\
    \ c : ch) {\n        if (!c) continue;\n        if (reversed) c->reverse();\n\
    \      }\n      reversed = false;\n    }\n\n    u32 which_child() const { return\
    \ fa->ch[1] == this; }\n\n    bool is_root() const\n    {\n      return fa ==\
    \ nullptr || (fa->ch[0] != this && fa->ch[1] != this);\n    }\n\n    void rotate()\n\
    \    {\n      auto x = this;\n\n      auto y = x->fa;\n      auto z = y->fa;\n\
    \      auto xci = which_child();\n      y->ch[xci] = x->ch[xci ^ 1];\n      if\
    \ (x->ch[xci ^ 1]) x->ch[xci ^ 1]->fa = y;\n      x->ch[xci ^ 1] = y;\n      if\
    \ (!y->is_root()) z->ch[y->which_child()] = x;\n      y->fa = x;\n      x->fa\
    \ = z;\n\n      y->update();\n      x->update();\n    }\n\n    void splay()\n\
    \    {\n      push();\n      while (!is_root()) {\n        auto y = fa;\n    \
    \    if (y->is_root()) {\n          y->push();\n          push();\n          rotate();\n\
    \        } else {\n          auto z = y->fa;\n          z->push();\n         \
    \ y->push();\n          push();\n          if (y->which_child() == which_child())\
    \ y->rotate();\n          else rotate();\n          rotate();\n        }\n   \
    \   }\n    }\n\n    ptr access()\n    {\n      ptr rp = nullptr;\n      ptr cur\
    \ = this;\n      while (cur) {\n        cur->splay();\n        cur->ch[1] = rp;\n\
    \        cur->update();\n        rp = cur;\n        cur = cur->fa;\n      }\n\
    \      splay();\n      return rp;\n    }\n\n    void make_root()\n    {\n    \
    \  access();\n      reverse();\n    }\n  };\n\n  using ptr = typename Splay::ptr;\n\
    \n  std::vector<ptr> ptrs;\n\n  template <typename F> LinkCutTree(int n, F &&f)\
    \ : ptrs(n)\n  {\n    for (int i = 0; i < n; i++) ptrs[i] = new Splay(f(i));\n\
    \  }\n\n  void link(int x, int y)\n  {\n    auto xp = ptrs[x], yp = ptrs[y];\n\
    \    xp->make_root();\n    xp->fa = yp;\n  }\n\n  void cut(int x, int y)\n  {\n\
    \    auto xp = ptrs[x], yp = ptrs[y];\n    xp->make_root();\n    yp->access();\n\
    \    yp->ch[0] = xp->fa = nullptr;\n  }\n\n  T prod(int x, int y)\n  {\n    auto\
    \ xp = ptrs[x], yp = ptrs[y];\n    xp->make_root();\n    yp->access();\n    return\
    \ yp->prod;\n  }\n\n  void set(int x, const T &v)\n  {\n    auto xp = ptrs[x];\n\
    \    xp->splay();\n    xp->set(v);\n  }\n\n  void multiply(int x, const T &v)\n\
    \  {\n    auto xp = ptrs[x];\n    xp->splay();\n    xp->set(xp->val * v);\n  }\n\
    \n  T get(int x) { return ptrs[x]->val; }\n};\n"
  dependsOn:
  - lib/internal.hpp
  isVerificationFile: false
  path: lib/ds/lct.hpp
  requiredBy: []
  timestamp: '2024-06-14 09:23:51+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/ds/dynamic_tree_vertex_add_path_sum.test.cpp
documentation_of: lib/ds/lct.hpp
layout: document
redirect_from:
- /library/lib/ds/lct.hpp
- /library/lib/ds/lct.hpp.html
title: Link Cut Tree
---