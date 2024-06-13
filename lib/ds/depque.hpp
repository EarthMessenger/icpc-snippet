#pragma once
#include "lib/internal.hpp"
#include <queue>

/**
 * @brief Double Ended Priority Queue
 *
 * @tparam T    elements' type
 * @tparam Comp compare for min opt
 */
template <typename T, class MinComp = std::less<T>,
          class MaxComp = std::greater<T>>
class DEPQ
{
private:
  u32 sz;
  vec<T> a;
  vec<char> del;

  template <typename C> struct PosComp
  {
    const vec<T> &v;
    C comp;
    explicit PosComp(const vec<T> &u, C c) : v(u), comp(c) {}
    bool operator()(u32 x, u32 y) { return comp(v[x], v[y]); }
  };

  std::priority_queue<u32, vec<u32>, PosComp<MinComp>> mnh; // min heap
  std::priority_queue<u32, vec<u32>, PosComp<MaxComp>> mxh; // max heap

  void fresh_min()
  {
    while (!mnh.empty() && del[mnh.top()]) mnh.pop();
  }
  void fresh_max()
  {
    while (!mxh.empty() && del[mxh.top()]) mxh.pop();
  }

public:
  DEPQ(const MinComp &mnc = MinComp(), const MaxComp &mxc = MaxComp())
      : sz(), a(), del(), mnh(PosComp(a, mnc)), mxh(PosComp(a, mxc))
  {
  }
  template <typename It>
  DEPQ(It first, It second, const MinComp &mnc = MinComp(),
       const MaxComp &mxc = MaxComp())
      : sz(second - first), a(first, second), del(sz), mnh([this, mnc]() {
          std::vector<u32> b(this->size());
          for (u32 i = 0; i < this->size(); i++) b[i] = i;
          return std::priority_queue(b.begin(), b.end(), PosComp(a, mnc));
        }()),
        mxh([this, mxc]() {
          std::vector<u32> b(this->size());
          for (u32 i = 0; i < this->size(); i++) b[i] = i;
          return std::priority_queue(b.begin(), b.end(), PosComp(a, mxc));
        }())
  {
  }

  T min() { return fresh_min(), a[mnh.top()]; }
  T max() { return fresh_max(), a[mxh.top()]; }

  constexpr u32 size() { return sz; }

  void pop_min()
  {
    fresh_min();
    del[mnh.top()] = true;
    mnh.pop();
    --sz;
  }

  void pop_max()
  {
    fresh_max();
    del[mxh.top()] = true;
    mxh.pop();
    --sz;
  }

  void push(const T &x)
  {
    a.emplace_back(x);
    del.emplace_back();
    mnh.push(a.size() - 1u);
    mxh.push(a.size() - 1u);
    ++sz;
  }
};