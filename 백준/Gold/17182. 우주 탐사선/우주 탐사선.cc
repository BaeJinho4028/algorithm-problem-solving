#include <bits/stdc++.h>
using namespace std;

int n, m;
int d[10][10];
vector<vector<int>> dp(10, vector<int>(1 << 10, -1));

int dfs(int cur, int vis) {
    if (vis == (1 << n) - 1) return 0;

    int& ret = dp[cur][vis];
    if (~ret) return ret;

    ret = '????';
    for (int i = 0; i < n; ++i) {
        if (vis & (1 << i)) continue;

        ret = min(ret, d[cur][i] + dfs(i, vis | (1 << i)));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> d[i][j];
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j< n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    cout << dfs(m, 1 << m);
}
