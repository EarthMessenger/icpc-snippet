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
  bundledCode: "#line 1 \"lib/str/sam.hpp\"\nstruct suffix_automaton\n{\n  struct\
    \ node_t\n  {\n    std::array<int, 26> next;\n    int link;\n    int len;\n  \
    \  node_t() : link(0), len(0) { std::fill(next.begin(), next.end(), -1); }\n \
    \ };\n\n  int n;\n  std::vector<node_t> t;\n  int last;\n\n  suffix_automaton()\
    \ : n(0), t(1), last(0) {}\n\n  int new_node()\n  {\n    int id = t.size();\n\
    \    t.emplace_back();\n    return id;\n  }\n\n  int size() const { return t.size();\
    \ }\n\n  void append(char ch)\n  {\n    int cv = ch - 'a';\n    int x = new_node();\n\
    \    t[x].len = n + 1;\n    int p = last;\n    while (p != 0 && t[p].next[cv]\
    \ == -1) {\n      t[p].next[cv] = x;\n      p = t[p].link;\n    }\n    if (t[p].next[cv]\
    \ == -1) {\n      t[p].next[cv] = x;\n    } else {\n      int q = t[p].next[cv];\n\
    \      if (t[p].len + 1 == t[q].len) {\n        t[x].link = q;\n      } else {\n\
    \        int nq = new_node();\n        t[nq].next = t[q].next;\n        t[nq].link\
    \ = t[q].link;\n        t[q].link = nq;\n        t[nq].len = t[p].len + 1;\n \
    \       while (p != 0 && t[p].next[cv] == q) {\n          t[p].next[cv] = nq;\n\
    \          p = t[p].link;\n        }\n        if (t[p].next[cv] == q) t[p].next[cv]\
    \ = nq;\n        t[x].link = nq;\n      }\n    }\n    last = x;\n    n++;\n  }\n\
    };\n"
  code: "struct suffix_automaton\n{\n  struct node_t\n  {\n    std::array<int, 26>\
    \ next;\n    int link;\n    int len;\n    node_t() : link(0), len(0) { std::fill(next.begin(),\
    \ next.end(), -1); }\n  };\n\n  int n;\n  std::vector<node_t> t;\n  int last;\n\
    \n  suffix_automaton() : n(0), t(1), last(0) {}\n\n  int new_node()\n  {\n   \
    \ int id = t.size();\n    t.emplace_back();\n    return id;\n  }\n\n  int size()\
    \ const { return t.size(); }\n\n  void append(char ch)\n  {\n    int cv = ch -\
    \ 'a';\n    int x = new_node();\n    t[x].len = n + 1;\n    int p = last;\n  \
    \  while (p != 0 && t[p].next[cv] == -1) {\n      t[p].next[cv] = x;\n      p\
    \ = t[p].link;\n    }\n    if (t[p].next[cv] == -1) {\n      t[p].next[cv] = x;\n\
    \    } else {\n      int q = t[p].next[cv];\n      if (t[p].len + 1 == t[q].len)\
    \ {\n        t[x].link = q;\n      } else {\n        int nq = new_node();\n  \
    \      t[nq].next = t[q].next;\n        t[nq].link = t[q].link;\n        t[q].link\
    \ = nq;\n        t[nq].len = t[p].len + 1;\n        while (p != 0 && t[p].next[cv]\
    \ == q) {\n          t[p].next[cv] = nq;\n          p = t[p].link;\n        }\n\
    \        if (t[p].next[cv] == q) t[p].next[cv] = nq;\n        t[x].link = nq;\n\
    \      }\n    }\n    last = x;\n    n++;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/str/sam.hpp
  requiredBy: []
  timestamp: '2024-06-14 21:09:19+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/str/sam.hpp
layout: document
redirect_from:
- /library/lib/str/sam.hpp
- /library/lib/str/sam.hpp.html
title: lib/str/sam.hpp
---
