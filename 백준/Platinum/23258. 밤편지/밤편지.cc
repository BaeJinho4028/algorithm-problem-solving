#include <bits/stdc++.h>
using namespace std;

int d[302][302][302];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> d[0][i][j];
            if (d[0][i][j] == 0 && i != j) {
                d[0][i][j] = '????';
            }
        }
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                d[k][i][j] = min(d[k - 1][i][j], d[k - 1][i][k] + d[k - 1][k][j]);
            }
        }
    }

    while (q--) {
        int c, s, e;
        cin >> c >> s >> e;

        int ans = d[c - 1][s][e];
        cout << (ans < '????' ? ans : -1) << '\n';
    }
}
