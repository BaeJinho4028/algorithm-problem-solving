#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int y, x;
    cin >> y >> x;

    vector<string> board(x);
    vector<pair<int, int>> c;
    for (int i = 0; i < x; ++i) {
        cin >> board[i];
        for (int j = 0; j < y; ++j) {
            if (board[i][j] == 'C') {
                c.push_back({i, j});
            }
        }
    }

    vector<vector<vector<int>>> d(x, vector<vector<int>>(y, vector<int>(4, '????')));
    priority_queue<tuple<int ,int ,int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
    auto [sx, sy] = c[0];
    for (int dir = 0; dir < 4; ++dir) {
        d[sx][sy][dir] = 0;
        pq.push({0, sx, sy, dir});
    }

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    while (!pq.empty()) {
        auto [cm, cx, cy, cd] = pq.top(); pq.pop();

        if (cm != d[cx][cy][cd]) continue;
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if (nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
            if (board[nx][ny] == '*') continue;

            int nm = cm + (cd != dir);

            if (d[nx][ny][dir] > nm) {
                d[nx][ny][dir] = nm;
                pq.push({nm, nx, ny, dir});
            }
        }
    }

    auto [ex, ey] = c[1];
    cout << *min_element(begin(d[ex][ey]), end(d[ex][ey]));
}
