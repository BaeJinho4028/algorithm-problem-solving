#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, hx, hy, ex, ey;
    cin >> n >> m >> hx >> hy >> ex >> ey;

    int board[n + 1][m + 1];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> board[i][j];
        }
    }

    queue<tuple<int, int, int>> q;
    int dist[n + 1][m + 1][2];
    memset(dist, -1, sizeof(dist));

    q.push({hx, hy, 0});
    dist[hx][hy][0] = 0;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    while (!q.empty()) {
        auto [cx, cy, cw] = q.front();
        q.pop();

        if (cx == ex && cy == ey) {
            cout << dist[cx][cy][cw];
            return 0;
        }

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (dist[nx][ny][cw] != -1) continue;

            if (!cw && board[nx][ny] == 1) {
                if (dist[nx][ny][1] == -1) {
                    dist[nx][ny][1] = dist[cx][cy][cw] + 1;
                    q.push({nx, ny, 1});
                }
            }
            if (board[nx][ny] == 0) {
                if (dist[nx][ny][cw] == -1) {
                    dist[nx][ny][cw] = dist[cx][cy][cw] + 1;
                    q.push({nx, ny, cw});
                }
            }
        }
    }

    cout << -1;

    return 0;
}
