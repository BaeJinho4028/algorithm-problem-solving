#include <bits/stdc++.h>
using namespace std;

int n, m;
int s[10];
bool d[5002][5002];

void f(int x, int y) {
    if (x > n || d[x][y]) return;
    d[x][y] = true;
    for (int i = 0; i < m; ++i) {
        f(x + y + s[i], y + s[i]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;

        for (int i = 0; i < m; ++i) {
            cin >> s[i];
        }

        for (int i = 0; i <= n; ++i) {
            fill(d[i], d[i] + n + 1, false);
        }

        f(0, 0);

        int ans = -1;
        for (int i = 0; i <= n; ++i) {
            if (d[n][i]) ans = i;
        }
        cout << ans << '\n';
    }
}
