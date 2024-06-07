#pragma once

template <typename T> int lucas(long long n, long long m, T binom)
{
  static constexpr int P = 2;
  if (m == 0) return 1;
  return (long long)binom(n % P, m % P) * lucas(n / P, m / P) % P;
}
