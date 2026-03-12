#include <bits/stdc++.h>
using namespace std;

int mx = 0;

void rotate(int cur, const int n, vector<vector<int>>& v);

void slide(int cur, int n, const vector<vector<int>>& v) {
    vector<vector<int>> line(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        queue<int> q;
        for (int j = 0; j < n; ++j) {
            if (v[i][j]) {
                q.push(v[i][j]);
            }
        }

        int idx = 0;
        int x = 0;
        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
        
            if (x == 0) {
                x = tmp;
            }
            else if (x == tmp) {
                line[i][idx++] = x * 2;
                x = 0;
            }
            else {
                line[i][idx++] = x;
                x = tmp;
            }
        }
        if (x != 0 && idx < n) {
            line[i][idx] = x;
        }
    }

    rotate(cur + 1, n, line);
}

void chk(int n, const vector<vector<int>>& v) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mx = max(mx, v[i][j]);
        }
    }
}

void rotate(int cur, const int n, vector<vector<int>>& v) {
    if (cur >= 5) {
        chk(n, v);
        return;
    }

    slide(cur, n, v);

    vector<vector<int>> tmp(n, vector<int>(n, 0));
    for (int dir = 0; dir < 3; ++dir) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                tmp[i][j] = v[n - j - 1][i];
            }
        }
        slide(cur, n, tmp);
        v = tmp;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
        }
    }

    rotate(0, n, v);

    cout << mx;
}
