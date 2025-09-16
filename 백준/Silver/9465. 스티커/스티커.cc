#include <bits/stdc++.h>
using namespace std;

int v[3][100'005];
int d[3][100'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= 2; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> v[i][j];
            }
        }

        d[1][1] = v[1][1];
        d[2][1] = v[2][1];
        for (int i = 2; i <= n; ++i) {
            d[1][i] = max(d[2][i - 1], d[2][i - 2]) + v[1][i];
            d[2][i] = max(d[1][i - 1], d[1][i - 2]) + v[2][i];  
        }

        cout << max(d[1][n], d[2][n]) << '\n';
    }
}
