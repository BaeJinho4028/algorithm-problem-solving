#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> v;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            v.push_back({x, i});
        }
    }
    sort(v.begin(), v.end());

    int ans = '????';

    int st = 0, en = 0;
    int cnt = 0;
    vector<int> chk(n + 1);
    while (st < n * m) {
        while (cnt < n && en < n * m) {
            if (chk[v[en++].second]++ == 0) cnt++;
        }
        if (cnt != n) break;

        ans = min(ans, v[en - 1].first - v[st].first);
        if (--chk[v[st++].second] == 0) cnt--;
    }

    cout << ans;
}
