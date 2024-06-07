#include "lib/internal.hpp"

std::vector<int> get_prime(const int n)
{
  std::vector<int> res;
  std::vector<bool> vis(n + 1);
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) { res.emplace_back(i); }
    for (auto j : res) {
      if ((long long)i * j > n) break;
      vis[i * j] = true;
      if (i % j == 0) break;
    }
  }
  return res;
}
