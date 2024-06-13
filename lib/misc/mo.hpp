#pragma once

#include <vector>
#include <utility>
#include <algorithm>

/**
 * @brief Mo's Algorithm
 */
struct mo_algorithm
{
  std::vector<std::pair<int, int>> q;
 
  void add_query(int l, int r)
  {
    q.emplace_back(l, r);
  }
 
  std::vector<int> sort() const
  {
    int n = 0;
    for (auto i : q) n = std::max({n, i.first, i.second});
    int bs = std::max(1, (int)(n / std::sqrt(q.size())));
    std::vector<int> ord(q.size());
    for (int i = 0; i < (int)q.size(); i++) ord[i] = i;
    std::sort(ord.begin(), ord.end(),
              [&bs, this](int x, int y)
              {
                int xb = q[x].first / bs, yb = q[y].first / bs;
                if (xb != yb) return xb < yb;
                else if (xb % 2 == 0) return q[x].second < q[y].second;
                else return q[x].second > q[y].second;
              });
    return ord;
  }
 
  template <typename F0, typename F1, typename F2>
  void solve(const F0 &add,
             const F1 &del,
             const F2 &ans) const
  {
    solve(add, add, del, del, ans);
  }
 
  template <typename F0, typename F1, typename F2, typename F3, typename F4>
  void solve(const F0 &add_l,
             const F1 &add_r,
             const F2 &del_l,
             const F3 &del_r,
             const F4 &ans) const
  {
    auto ord = sort();
    int l = 0, r = 0;
    for (auto i : ord) {
      while (q[i].first < l)  add_l(--l);
      while (r < q[i].second) add_r(r++);
      while (l < q[i].first)  del_l(l++);
      while (q[i].second < r) del_r(--r);
      ans(i);
    }
  }

  template <typename F0, typename F1, typename F2, typename F3>
  auto only_move(const F0 &left_l,
                 const F1 &right_r,
                 const F2 &right_l,
                 const F3 &left_r) const
  {
    auto ord = sort();
    int l = 0, r = 0;
    for (auto i : ord) {
      if (q[i].first < l) {
        left_l(q[i].first, l, r, i);
        l = q[i].first;
      }
      if (r < q[i].second) {
        right_r(l, r, q[i].second, i);
        r = q[i].second;
      }
      if (l < q[i].first) {
        right_l(l, q[i].first, r, i);
        l = q[i].first;
      }
      if (q[i].second < r) {
        left_r(l, q[i].second, r, i);
        r = q[i].second;
      }
    }
    return ord;
  }
};
