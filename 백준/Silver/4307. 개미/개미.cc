#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int l, n;
        cin >> l >> n;

        int mn = 0, mx = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;

            mn = max(mn, min(l - x, x));
            mx = max(mx, max(l - x, x));
        }

        cout << mn << ' ' << mx << '\n';
    }
}
