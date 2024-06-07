#pragma once
#include "lib/internal.hpp"

int gcd(int a, int b)
{
  int az = __builtin_ctz(a);
  int bz = __builtin_ctz(b);
  int z = std::min(az, bz);
  b >>= bz;
  while (a) {
    a >>= az;
    int diff = a - b;
    az = __builtin_ctz(diff);
    b = std::min(a, b);
    a = std::abs(diff);
  }
  return b << z;
}