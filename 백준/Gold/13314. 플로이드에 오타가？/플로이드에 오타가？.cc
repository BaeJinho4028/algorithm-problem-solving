#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 100;
    int d[102][102];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            d[i][j] = 10000;
            if (i == n || j == n) d[i][j] = 4999;
            if (i == j) d[i][j] = 0;
        }
    }

    cout << n << '\n';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << d[i][j] << ' ';
            if (j == n) cout << '\n';
        }
    }
}
