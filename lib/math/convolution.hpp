#pragma once
#include "lib/internal.hpp"

namespace poly {

namespace details {

vec<u32> r[30];
const vec<u32> &calc(const u32 n)
{
  if (r[n].size()) return r[n];
  u32 q = 1 << n, p = q / 2;
  r[n].resize(q);
  for (u32 i = 1; i < q; i++) {
    r[n][i] = r[n][i / 2] / 2;
    if (i % 2) r[n][i] += p;
  }
  return r[n];
}

} // namespace details

template <typename T> void reverse_transform(const u32 n, vec<T> &a)
{
  const auto &r = details::calc(n);
  u32 q = 1 << n;
  for (u32 i = 0; i < q; i++) {
    if (i < r[i]) std::swap(a[i], a[r[i]]);
  }
}

template <bool d, class B, class I, typename T>
void fourier_transform(const u32 n, vec<T> &a, B base, I inv, T e)
{
  reverse_transform(n, a);
  u32 q = 1 << n;
  for (u32 h = 2; h <= q; h *= 2) {
    T b = base(h);
    for (u32 j = 0; j < q; j += h) {
      T w(e);
      for (u32 k = j, l = h / 2; k < j + l; k++) {
        T u = a[k], v = w * a[k + l];
        a[k] = u + v;
        a[k + l] = u - v;
        w = w * b;
      }
    }
  }
  if constexpr (d) {
    for (u32 i = 0; i < q; i++)
      inv(a[i], q);
  }
}

} // namespace poly

namespace poly {

namespace bit {

template <typename T> void compliment(u32 n, vec<T> &a)
{
  u32 q = 1 << n;
  for (u32 i = 0; i < q; i++) {
    if (i & 1) std::swap(a[i], a[(~i) & (q - 1)]);
  }
}

template <bool dir, typename T> void sosdp(u32 n, vec<T> &a)
{
  u32 q = 1 << n;
  for (u32 i = 0; i < n; i++) {
    for (u32 j = 0; j < q; j++) {
      if ((j >> i) & 1) {
        if constexpr (!dir) a[j] += a[j ^ (1 << i)];
        else a[j] -= a[j ^ (1 << i)];
      }
    }
  }
}

} // namespace bit

} // namespace poly