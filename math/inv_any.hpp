#include <vector>

constexpr int M = 998'244'353;
int inv(int x);

std::vector<int> get_inv(const std::vector<int> &a)
{
  const int n = a.size();
  std::vector<int> s(n + 1), sv(n + 1), res(n);
  s[0] = 1;
  for (int i = 0; i < n; i++) { s[i + 1] = (long long)s[i] * a[i] % M; }
  sv[n] = inv(s[n]);
  for (int i = n; i > 0;) {
    i--;
    sv[i] = (long long)sv[i + 1] * a[i] % M;
  }
  for (int i = 0; i < n; i++) { res[i] = (long long)sv[i + 1] * s[i] % M; }
  return res;
}
