#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "lib/misc/bitop.hpp"
#include "lib/math/convolution.hpp"
#include "lib/math/static_modint.hpp"

signed main() 
{
    using namespace std;
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    using mint = static_modint<998244353>;
    auto read_int = [x = int()]() mutable { return cin >> x, x; };
    u32 n = read_int(), m = read_int();
    u32 p = lg2(max(btc(n), btc(m))) + 1, q = 1 << p;
    vec<mint> a(q), b(q);
    for (u32 i = 0; i < n; i++) a[i] = read_int();
    for (u32 i = 0; i < m; i++) b[i] = read_int();
    auto base = [](u32 h) { return mint::raw(3).pow(998244352 / h); };
    auto inv = [iv2 = mint(q).inv()](mint &x,[[maybe_unused]] u32 y){x *= iv2;};
    poly::fourier_transform<0>(p, a, base, inv, mint::raw(1));
    poly::fourier_transform<0>(p, b, base, inv, mint::raw(1));
    for (u32 i = 0; i < q; i++) a[i] *= b[i];
    poly::fourier_transform<1>(p, a, base, inv, mint::raw(1));
    reverse(a.begin() + 1, a.end());
    for (u32 i = 0; i < n + m - 1; i++) cout << a[i].val() << ' ';
    cout << '\n';
    return 0;
}