#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> m >> n;

    vector<vector<int>> board(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            board[i][j] = s[j] - '0';
        }
    }

    vector<vector<int>> d(n, vector<int>(m, '????'));
    d[0][0] = 0;

    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    pq.push({d[0][0], 0, 0});

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    while (!pq.empty()) {
        auto [cw, cx, cy] = pq.top(); pq.pop();
        if (d[cx][cy] != cw) continue;

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            int nw = cw + board[nx][ny];
            if (d[nx][ny] > nw) {
                d[nx][ny] = nw;
                pq.push({nw, nx, ny});
            }
        }
    }
    cout << d[n - 1][m - 1];

    return 0;
}
