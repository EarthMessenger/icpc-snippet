#include <algorithm>
#include <array>
#include <queue>
#include <string>

struct aho_corasick
{
  struct node_t
  {
    std::array<int, 26> next;
    int fail;
    node_t() : fail(0) { std::fill(next.begin(), next.end(), 0); }
    int &operator[](int x) { return next[x]; }
    int operator[](int x) const { return next[x]; }
  };

  std::vector<node_t> t;

  aho_corasick() : t(1) {}

  int insert(const std::string &s)
  {
    int p = 0;
    for (auto c : s) {
      c -= 'a';
      if (!t[p][c]) {
        int id = t.size();
        t.emplace_back();
        t[p][c] = id;
      }
      p = t[p][c];
    }
    return p;
  }

  void build()
  {
    std::queue<int> q;
    for (int i = 0; i < 26; i++) {
      if (t[0][i]) q.emplace(t[0][i]);
    }
    while (!q.empty()) {
      auto u = q.front();
      q.pop();
      for (auto i = 0; i < 26; i++) {
        int &v = t[u][i];
        if (v) {
          t[v].fail = t[t[u].fail][i];
          q.emplace(v);
        } else {
          v = t[t[u].fail][i];
        }
      }
    }
  }

  int walk(int u, char ch) const { return t[u][ch - 'a']; }

  int size() const { return t.size(); }

  std::vector<std::vector<int>> fail_tree() const
  {
    int n = size();
    std::vector<int> deg(n);
    for (int i = 1; i < n; i++) deg[t[i].fail]++;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n; i++) adj[i].reserve(deg[i]);
    for (int i = 1; i < n; i++) adj[t[i].fail].emplace_back(i);
    return adj;
  }
};
