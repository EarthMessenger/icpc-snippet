#pragma once
#include <tuple>

// 给定 $a$ 和 $b$，返回三元组 $(d, x, y)$ 使得 $d = \gcd(a, b)$，$ax + by = d$
std::tuple<int, int, int> ex_euclid(int a, int b)
{
  if (b == 0) return {a, 1, 0};
  auto [d, x, y] = ex_euclid(b, a % b);
  return {d, y, x - (a / b) * y};
}
