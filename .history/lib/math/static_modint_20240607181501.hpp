#pragma once
#include "lib/internal.hpp"

template <int M>
struct static_modint
{
  static constexpr u32 UM = M;
  static_assert(UM < 0x80'00'00'00u);

  u32 v;
  constexpr static_modint() : v(0) {}

  template <typename T, std::enable_if_t<std::is_signed_v<T>>* = nullptr>
  constexpr static_modint(T n) : v((n %= M) < 0 ? n + M : n) {}

  template <typename T, std::enable_if_t<std::is_unsigned_v<T>>* = nullptr>
  constexpr static_modint(T n) : v(n %= UM) {}

  using mint = static_modint;

  static mint raw(u32 v)
  {
    mint res;
    res.v = v;
    return res;
  }

  constexpr u32 val() const { return v; }

  mint operator-() const { return mint::raw(v == 0 ? 0u : UM - v); }

  mint &operator+=(mint a)
  {
    if ((v += a.v) >= UM) v -= UM;
    return *this;
  }
  mint &operator-=(mint a)
  {
    if ((v += UM - a.v) >= UM) v -= UM;
    return *this;
  }
  mint &operator*=(mint a)
  {
    v = (u64)v * a.v % UM;
    return *this;
  }
  mint &operator/=(mint a) { return *this *= a.inv(); }

  friend mint operator+(mint a, mint b) { return a += b; }
  friend mint operator-(mint a, mint b) { return a -= b; }
  friend mint operator*(mint a, mint b) { return a *= b; }
  friend mint operator/(mint a, mint b) { return a /= b; }

  mint pow(u64 n) const
  {
    mint res = 1, base = *this;
    while (n) {
      if (n & 1) res *= base;
      base *= base;
      n >>= 1;
    }
    return res;
  }

  mint inv() const { return pow(UM - 2); }
};
