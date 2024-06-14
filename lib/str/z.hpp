#include <vector>
#include <string>

std::vector<int> z_algorithm(const std::string &s)
{
  int n = s.size();
  std::vector<int> z(n + 1);
  z[0] = n;
  int l = 0, r = 0;
  for (int i = 1; i <= n; i++) {
    int t = 0;
    if (i <= r) t = std::min(z[i - l], r - i);
    while (i + t < n && s[t] == s[i + t]) t++;
    z[i] = t;
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}
