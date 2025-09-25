#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n + 1);
    vector<vector<bool>> d(n + 1, vector<bool>(n + 1));
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        d[i][i] = 1;
        if (v[i - 1] == v[i]) d[i - 1][i] = 1;
    }

    for (int len = 3; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            if (v[i] == v[j] && d[i + 1][j - 1]) {
                d[i][j] = true;
            }
        }
    }    

    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << d[a][b] << '\n';
    }
}
