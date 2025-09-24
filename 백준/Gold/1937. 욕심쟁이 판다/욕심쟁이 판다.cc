#include <bits/stdc++.h>
using namespace std;

int n;
int board[502][502];
int d[502][502];

int dfs(int x, int y) {
    if (d[x][y] != 0) return d[x][y];
    d[x][y] = 1;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (board[nx][ny] > board[x][y]) {
            d[x][y] = max(d[x][y], dfs(nx, ny) + 1);
        }
    }
    return d[x][y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    int mx = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mx = max(mx, dfs(i, j));
        }
    }

    cout << mx;
}
