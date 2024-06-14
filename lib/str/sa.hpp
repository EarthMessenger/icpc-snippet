#pragma once

#include <vector>
#include <string>
#include <utility>

// 0-indexed
std::pair<std::vector<int>, std::vector<int>> suffix_array(const std::string &s)
{
  int n = s.size();
  int m = std::max(128, n);

  std::vector<int> sa(n), rk(n), sa2(n), rk2(n * 2, -1), cnt(m + 1);
  for (int i = 0; i < n; i++) rk[i] = s[i];
  for (int i = 0; i < n; i++) cnt[rk[i] + 1]++;
  for (int i = 1; i < m; i++) cnt[i] += cnt[i - 1];
  for (int i = 0; i < n; i++) sa[cnt[rk[i]]++] = i;

  for (int w = 1;; w *= 2) {
    int p = 0;
    for (int i = n - w; i < n; i++) sa2[p++] = i;
    for (int i = 0; i < n; i++) {
      if (sa[i] >= w) sa2[p++] = sa[i] - w;
    }

    std::fill(cnt.begin(), cnt.end(), 0);
    for (int i = 0; i < n; i++) cnt[rk[sa2[i]] + 1]++;
    for (int i = 1; i < m; i++) cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++) sa[cnt[rk[sa2[i]]]++] = sa2[i];

    std::copy(rk.begin(), rk.end(), rk2.begin());
    int q = 0;
    rk[sa[0]] = 0;
    for (int i = 1; i < n; i++) {
      int u = sa[i - 1], v = sa[i];
      if (rk2[u] != rk2[v] || rk2[u + w] != rk2[v + w]) q++;
      rk[sa[i]] = q;
    }
    if (q + 1 == n) break;
  }

  return {sa, rk};
}

// h[i] = lcp(s[sa[i]], s[sa[i + 1]])
std::vector<int> calc_height(const std::string &s, const std::vector<int> &sa,
                             const std::vector<int> &rk)
{
  int n = s.size();
  std::vector<int> h(n);
  int p = 0;
  for (int i = 0; i < n; i++) {
    p = std::max(0, p - 1);
    if (rk[i] + 1 == n) continue;
    int j = sa[rk[i] + 1];
    int mij = std::max(i, j);
    while (mij + p < n && s[i + p] == s[j + p]) p++;
    h[rk[i]] = p;
  }
  return h;
}
