#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }

    vector<int> ans(n, '????');
    for (auto [x, _] : v) {
        for (auto [_, y] : v) {
            vector<int> w;
            
            for (auto [a, b] : v) {
                w.push_back(abs(x - a) + abs(y - b));
            }

            sort(w.begin(), w.end());

            int cost = 0;
            for (int i = 0; i < n; ++i) {
                cost += w[i];
                ans[i] = min(ans[i], cost);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
}
