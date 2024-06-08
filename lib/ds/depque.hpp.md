---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/internal.hpp
    title: lib/internal.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: verify/ds/double_ended_priority_queue.FIXME.cpp
    title: verify/ds/double_ended_priority_queue.FIXME.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: double ended priority queue
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ lib/ds/depque.hpp: line 3: #pragma once found in a non-first line\n"
  code: "// FIXME\n\n#pragma once\n#include \"lib/internal.hpp\"\n#include <queue>\n\
    \n/**\n * @brief double ended priority queue\n * \n * @tparam T    elements' type\n\
    \ * @tparam Comp compare for min opt\n */\ntemplate<typename T, \n    class MinComp\
    \ = std::less<T>, class MaxComp = std::greater<T>>\nclass DEPQ\n{\nprivate:\n\
    \    u32 sz;\n    vec<T> a;\n    vec<char> del;\n\n    template<typename C>\n\
    \    struct PosComp\n    {\n        const vec<T> &v;\n        C comp;\n      \
    \  explicit PosComp(const vec<T> &u, C c): v(u), comp(c) { }\n        bool operator()(u32\
    \ x, u32 y) { return comp(v[x], v[y]); }\n    };\n\n    std::priority_queue<u32,\
    \ vec<u32>, PosComp<MinComp>> mnh; // min heap\n    std::priority_queue<u32, vec<u32>,\
    \ PosComp<MaxComp>> mxh; // max heap\n\n\n    void fresh_min() { while (!mnh.empty()\
    \ && del[mnh.top()]) mnh.pop(); }\n    void fresh_max() { while (!mxh.empty()\
    \ && del[mxh.top()]) mxh.pop(); }\n    \npublic:\n    DEPQ(const MinComp &mnc\
    \ = MinComp(), const MaxComp &mxc = MaxComp())\n        : sz(), a(), del(), mnh(PosComp(a,\
    \ mnc)), mxh(PosComp(a, mxc)) { }\n    template<typename It> DEPQ(It first, It\
    \ second, \n        const MinComp &mnc = MinComp(), const MaxComp &mxc = MaxComp())\n\
    \        : sz(second - first), a(first, second), del(sz), \n          mnh([this,\
    \ mnc](){\n            std::vector<u32> b(this->size()); \n            for (u32\
    \ i = 0; i < this->size(); i++) b[i] = i; \n            return std::priority_queue(b.begin(),\
    \ b.end(), PosComp(a, mnc));\n          }()), mxh([this, mxc](){\n           \
    \ std::vector<u32> b(this->size()); \n            for (u32 i = 0; i < this->size();\
    \ i++) b[i] = i; \n            return std::priority_queue(b.begin(), b.end(),\
    \ PosComp(a, mxc));\n          }()) { }\n\n\n    T min() { return fresh_min(),\
    \ a[mnh.top()]; }\n    T max() { return fresh_max(), a[mxh.top()]; }\n\n    constexpr\
    \ u32 size() { return sz; }\n\n    void pop_min()\n    {\n        fresh_min();\n\
    \        del[mnh.top()] = true;\n        mnh.pop();\n        --sz;\n    }\n\n\
    \    void pop_max()\n    {\n        fresh_max();\n        del[mxh.top()] = true;\n\
    \        mxh.pop();\n        --sz;\n    }\n\n    void push(const T &x)\n    {\n\
    \        a.emplace_back(x);\n        del.emplace_back();\n        mnh.push(a.size()\
    \ - 1u);\n        mxh.push(a.size() - 1u);\n        ++sz;\n    }\n};"
  dependsOn:
  - lib/internal.hpp
  isVerificationFile: false
  path: lib/ds/depque.hpp
  requiredBy:
  - verify/ds/double_ended_priority_queue.FIXME.cpp
  timestamp: '2024-06-08 15:08:56+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/ds/depque.hpp
layout: document
redirect_from:
- /library/lib/ds/depque.hpp
- /library/lib/ds/depque.hpp.html
title: double ended priority queue
---
