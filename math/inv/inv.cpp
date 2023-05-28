#include <vector>

constexpr int M = 998'244'353;

std::vector<int> get_inv(const int n)
{
    std::vector<int> res(n + 1);
    res[1] = 1;
    for (int i = 2; i <= n; i++) {
        res[i] = (long long)(M - M / i) * res[M % i] % M;
    }
    return res;
}
