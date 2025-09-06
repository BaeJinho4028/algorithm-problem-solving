#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, w;
    cin >> t >> w;

    vector<int> a(t + 1);
    for (int i = 1; i <= t; ++i) {
        cin >> a[i];
    }

    int cnt = 0;
    vector<vector<int>> d(t + 1, vector<int>(w + 1));
    for (int i = 1; i <= t; ++i) {
        if (a[i] == 1) cnt++;
        d[i][0] = cnt;
    }

    for (int i = 1; i <= t; ++i) {
        for (int j = 1; j <= w; ++j) {
            d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + (1 + j % 2 == a[i]);
        }
    }
    cout << *max_element(d[t].begin(), d[t].end());
}
