#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> bit(n + 1, 0);

    while (m--) {
        int op, i;
        cin >> op >> i;

        if (op == 1) {
            int x;
            cin >> x;
            bit[i] |= (1 << (x - 1));
        }
        else if (op == 2) {
            int x;
            cin >> x;
            bit[i] &= ~(1 << (x - 1));
        }
        else if (op == 3) {
            bit[i] <<= 1;
            bit[i] &= (1 << 20) - 1;
        }
        else {
            bit[i] >>= 1;
        }
    }

    set<int> se;
    for (int i = 1; i <= n; ++i) {
        se.insert(bit[i]);
    }

    cout << se.size();
    return 0;
}
