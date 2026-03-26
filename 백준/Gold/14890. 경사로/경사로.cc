#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l;
    cin >> n >> l;

    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int cnt = 1;
        bool flag = true;

        for (int j = 1; j < n; ++j) {
            if (v[i][j - 1] == v[i][j]) cnt++;
            else if (v[i][j - 1] - v[i][j] == -1 && cnt >= l) cnt = 1;
            else if (v[i][j - 1] - v[i][j] == 1 && cnt >= 0) cnt = -l + 1;
            else flag = false;
        }

        if (flag && cnt >= 0) {
            ans++;
        }
    }

    for (int i = 0; i < n; ++i) {
        int cnt = 1;
        bool flag = true;

        for (int j = 1; j < n; ++j) {
            if (v[j - 1][i] == v[j][i]) cnt++;
            else if (v[j - 1][i] - v[j][i] == -1 && cnt >= l) cnt = 1;
            else if (v[j - 1][i] - v[j][i] == 1 && cnt >= 0) cnt = -l + 1;
            else flag = false;
        }

        if (flag && cnt >= 0) {
            ans++;
        }
    }

    cout << ans;
}

