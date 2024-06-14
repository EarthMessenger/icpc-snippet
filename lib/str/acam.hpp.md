---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/str/acam.hpp\"\n#include <algorithm>\n#include <array>\n\
    #include <queue>\n#include <string>\n\nstruct aho_corasick\n{\n  struct node_t\n\
    \  {\n    std::array<int, 26> next;\n    int fail;\n    node_t() : fail(0) { std::fill(next.begin(),\
    \ next.end(), 0); }\n    int &operator[](int x) { return next[x]; }\n    int operator[](int\
    \ x) const { return next[x]; }\n  };\n\n  std::vector<node_t> t;\n\n  aho_corasick()\
    \ : t(1) {}\n\n  int insert(const std::string &s)\n  {\n    int p = 0;\n    for\
    \ (auto c : s) {\n      c -= 'a';\n      if (!t[p][c]) {\n        int id = t.size();\n\
    \        t.emplace_back();\n        t[p][c] = id;\n      }\n      p = t[p][c];\n\
    \    }\n    return p;\n  }\n\n  void build()\n  {\n    std::queue<int> q;\n  \
    \  for (int i = 0; i < 26; i++) {\n      if (t[0][i]) q.emplace(t[0][i]);\n  \
    \  }\n    while (!q.empty()) {\n      auto u = q.front();\n      q.pop();\n  \
    \    for (auto i = 0; i < 26; i++) {\n        int &v = t[u][i];\n        if (v)\
    \ {\n          t[v].fail = t[t[u].fail][i];\n          q.emplace(v);\n       \
    \ } else {\n          v = t[t[u].fail][i];\n        }\n      }\n    }\n  }\n\n\
    \  int walk(int u, char ch) const { return t[u][ch - 'a']; }\n\n  int size() const\
    \ { return t.size(); }\n\n  std::vector<std::vector<int>> fail_tree() const\n\
    \  {\n    int n = size();\n    std::vector<int> deg(n);\n    for (int i = 1; i\
    \ < n; i++) deg[t[i].fail]++;\n    std::vector<std::vector<int>> adj(n);\n   \
    \ for (int i = 0; i < n; i++) adj[i].reserve(deg[i]);\n    for (int i = 1; i <\
    \ n; i++) adj[t[i].fail].emplace_back(i);\n    return adj;\n  }\n};\n"
  code: "#include <algorithm>\n#include <array>\n#include <queue>\n#include <string>\n\
    \nstruct aho_corasick\n{\n  struct node_t\n  {\n    std::array<int, 26> next;\n\
    \    int fail;\n    node_t() : fail(0) { std::fill(next.begin(), next.end(), 0);\
    \ }\n    int &operator[](int x) { return next[x]; }\n    int operator[](int x)\
    \ const { return next[x]; }\n  };\n\n  std::vector<node_t> t;\n\n  aho_corasick()\
    \ : t(1) {}\n\n  int insert(const std::string &s)\n  {\n    int p = 0;\n    for\
    \ (auto c : s) {\n      c -= 'a';\n      if (!t[p][c]) {\n        int id = t.size();\n\
    \        t.emplace_back();\n        t[p][c] = id;\n      }\n      p = t[p][c];\n\
    \    }\n    return p;\n  }\n\n  void build()\n  {\n    std::queue<int> q;\n  \
    \  for (int i = 0; i < 26; i++) {\n      if (t[0][i]) q.emplace(t[0][i]);\n  \
    \  }\n    while (!q.empty()) {\n      auto u = q.front();\n      q.pop();\n  \
    \    for (auto i = 0; i < 26; i++) {\n        int &v = t[u][i];\n        if (v)\
    \ {\n          t[v].fail = t[t[u].fail][i];\n          q.emplace(v);\n       \
    \ } else {\n          v = t[t[u].fail][i];\n        }\n      }\n    }\n  }\n\n\
    \  int walk(int u, char ch) const { return t[u][ch - 'a']; }\n\n  int size() const\
    \ { return t.size(); }\n\n  std::vector<std::vector<int>> fail_tree() const\n\
    \  {\n    int n = size();\n    std::vector<int> deg(n);\n    for (int i = 1; i\
    \ < n; i++) deg[t[i].fail]++;\n    std::vector<std::vector<int>> adj(n);\n   \
    \ for (int i = 0; i < n; i++) adj[i].reserve(deg[i]);\n    for (int i = 1; i <\
    \ n; i++) adj[t[i].fail].emplace_back(i);\n    return adj;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/str/acam.hpp
  requiredBy: []
  timestamp: '2024-06-14 20:23:08+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/str/acam.hpp
layout: document
redirect_from:
- /library/lib/str/acam.hpp
- /library/lib/str/acam.hpp.html
title: lib/str/acam.hpp
---
