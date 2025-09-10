#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
        sort(v[i].begin(), v[i].end());
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    int mx = 0;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, v[i][0]);
        pq.push({v[i][0], i, 0});
    }

    int ans = '????';
    while (true) {
        auto [w, r, c] = pq.top(); pq.pop();
        ans = min(ans, mx - w);

        if (c == m - 1) break;

        mx = max(mx, v[r][c + 1]);
        pq.push({v[r][c + 1], r, c + 1});
    }
    cout << ans;
}
