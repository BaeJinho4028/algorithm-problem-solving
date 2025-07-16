#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> d(n + 1, vector<int>(n + 1, '????'));

    for (int i = 1; i <= n; ++i) {
        d[i][i] = 0;
    }

    vector<tuple<int, int, int>> e(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);
        e[i] = {u, v, w};
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    double mn = '????';
    for (int i = 1; i <= n; ++i) {
        double sum = 0;
        for (int j = 0; j < m; ++j) {
            auto [u, v, w] = e[j];
            sum = max(sum, (double)(d[i][u] + d[i][v] + w)/ 2);
        }
        mn = min(mn, sum);
    }
    cout << fixed;
    cout.precision(1);
    cout << mn;
}
