#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> board;
bool vis[10][10][10][10];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void move_ball(int x, int y, int dir, int &nx, int &ny, int &cnt, bool &goal) {
    nx = x;
    ny = y;
    cnt = 0;
    goal = false;

    while (board[nx + dx[dir]][ny + dy[dir]] != '#') {
        nx += dx[dir];
        ny += dy[dir];
        cnt++;

        if (board[nx][ny] == 'O') {
            goal = true;
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    board.resize(n);

    int rx, ry, bx, by;
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 'R') {
                rx = i;
                ry = j;
                board[i][j] = '.';
            }
            else if (board[i][j] == 'B') {
                bx = i;
                by = j;
                board[i][j] = '.';
            }
        }
    }

    queue<tuple<int, int, int, int, int>> q;
    q.push({rx, ry, bx, by, 0});
    vis[rx][ry][bx][by] = true;

    while (!q.empty()) {
        auto [crx, cry, cbx, cby, dist] = q.front();
        q.pop();

        if (dist >= 10) continue;

        for (int dir = 0; dir < 4; ++dir) {
            int nrx, nry, nbx, nby;
            int rcnt, bcnt;
            bool rgoal, bgoal;

            move_ball(crx, cry, dir, nrx, nry, rcnt, rgoal);
            move_ball(cbx, cby, dir, nbx, nby, bcnt, bgoal);

            if (bgoal) continue;
            if (rgoal) {
                cout << 1;
                return 0;
            }

            if (nrx == nbx && nry == nby) {
                if (rcnt > bcnt) {
                    nrx -= dx[dir];
                    nry -= dy[dir];
                } else {
                    nbx -= dx[dir];
                    nby -= dy[dir];
                }
            }

            if (!vis[nrx][nry][nbx][nby]) {
                vis[nrx][nry][nbx][nby] = true;
                q.push({nrx, nry, nbx, nby, dist + 1});
            }
        }
    }

    cout << 0;
}

