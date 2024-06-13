#include "lib/ds/depque.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"

signed main()
{
    using namespace std;
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    u32 n, q;
    cin >> n >> q;
    vec<int> s(n);
    for (int &i: s) cin >> i;
    sort(s.begin(), s.end());
    DEPQ<int> dq(s.begin(), s.end());
    u32 op, x;
    while (q--) {
        cin >> op;
        if (op == 1) {
            cout << dq.max() << '\n';
            dq.pop_max();
        }
        else if (op == 2) {
            cout << dq.min() << '\n';
            dq.pop_min();
        }
        else {
            cin >> x;
            dq.push(x);
        }
    }
}