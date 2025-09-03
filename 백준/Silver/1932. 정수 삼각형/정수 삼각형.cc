#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> v(n + 1, vector<int>(n + 1, 0)), d(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> v[i][j];
        }
    }

    d[0][0] = v[0][0];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + v[i][j];
        }
    }

    cout << *max_element(d[n].begin(), d[n].end());
}
