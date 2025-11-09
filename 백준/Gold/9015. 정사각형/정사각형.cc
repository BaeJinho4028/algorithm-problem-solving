#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        unordered_map<int, unordered_map<int, bool>> ma;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i].first >> v[i].second;
            ma[v[i].first][v[i].second] = true;
        }

        int ans = 0;
        int mx, my = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                auto [x1, y1] = v[i];
                auto [x2, y2] = v[j];

                int dx = x2 - x1;
                int dy = y2 - y1;
                if (ans > dx * dx + dy * dy) {
                    continue;
                }

                int x3 = x1 - dy, y3 = y1 + dx;
                int x4 = x2 - dy, y4 = y2 + dx;
                if (ma.count(x3) && ma[x3].count(y3) && ma.count(x4) && ma[x4].count(y4)) {
                    ans = max(ans, dx * dx + dy * dy);
                }

                x3 = x1 + dy, y3 = y1 - dx;
                x4 = x2 + dy, y4 = y2 - dx;
                if (ma.count(x3) && ma[x3].count(y3) && ma.count(x4) && ma[x4].count(y4)) {
                    ans = max(ans, dx * dx + dy * dy);
                }
            }
        }
        cout << ans << '\n';
    }
}

/*
두개를 선택하면 정해지잖아요 4점 체크해야하니 

3000 * 2999 * 4
*/
