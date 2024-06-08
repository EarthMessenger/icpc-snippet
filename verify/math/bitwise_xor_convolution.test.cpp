#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"

#include "lib/math/convolution.hpp"
#include "lib/math/static_modint.hpp"

signed main() 
{
    using namespace std;
    ios::sync_with_stdio(false); 
    cin.tie(0), cout.tie(0);
    auto read_int = [x = int()]() mutable { return cin >> x, x; };
    u32 n = read_int(), q = 1 << n;
    using mint = static_modint<998244353>;
    vec<mint> a(q), b(q);
    for (auto &i: a) i = read_int();
    for (auto &i: b) i = read_int();
    auto base = []([[maybe_unused]] u32 h) { return mint::raw(1); };
    auto inv = [inv2 = mint(q).inv()](mint &x, [[maybe_unused]] u32 m) { x *= inv2; };
    poly::fourier_transform<0>(n, a, base, inv, mint(1));
    poly::fourier_transform<0>(n, b, base, inv, mint(1));
    for (u32 i = 0; i < q; i++) a[i] *= b[i];
    poly::fourier_transform<1>(n, a, base, inv, mint(1));
    for (auto i: a) cout << i.val() << ' ';
    return 0;
}