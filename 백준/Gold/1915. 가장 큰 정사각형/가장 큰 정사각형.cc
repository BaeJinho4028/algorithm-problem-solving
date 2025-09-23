#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n + 1, vector<int>(m + 1)), d(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;

        for (int j = 1; j <= m; ++j) {
            v[i][j] = s[j - 1] - '0';
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (v[i][j]) {
                d[i][j] = min({d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]}) + 1;
                ans = max(ans, d[i][j]);
            }
        }
    }
    cout << ans * ans;
}
