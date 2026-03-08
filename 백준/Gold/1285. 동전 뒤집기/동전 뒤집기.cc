#include <bits/stdc++.h>
using namespace std;

int n;
int mn = '????';

void f(int cur, vector<vector<bool>> v) {
    if (cur >= n) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int t = 0;
            for (int j = 0; j < n; ++j) {
                t += v[j][i];
            }
            sum += min(t, n - t);
        }
        mn = min(mn, sum);
        return;
    }

    f(cur + 1, v);

    for (int i = 0; i < n; ++i) {
        v[cur][i] = !v[cur][i];
    }
    f(cur + 1, v);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    vector<vector<bool>> v(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            if (c == 'T') v[i][j] = true;
        }
    }

    f(0, v);
    cout << mn;
}
