#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <iostream>
#include <string>
#include "lib/str/z.hpp"

int main()
{
  std::string s;
  std::cin >> s;
  auto res = z_algorithm(s);
  res.pop_back();
  for (auto i : res) std::cout << i << " ";
  std::cout << std::endl;
}
