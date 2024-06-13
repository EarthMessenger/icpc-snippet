#include "lib/ds/segtree.hpp"

#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <functional>

signed main()
{
    using namespace std;
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    u32 n, q;
    cin >> n >> q;
    vec<i64> a(n);
    for (auto &i: a) cin >> i;
    SegmentTree s(n, [&a](u32 i) {return a[i];}, 0ll, plus());
    long long op, x, y;
    while (q--) {
        cin >> op >> x >> y;
        if (op == 0) s.set(x, a[x] += y);
        else cout << s.prod(x, y) << '\n';
    }
}