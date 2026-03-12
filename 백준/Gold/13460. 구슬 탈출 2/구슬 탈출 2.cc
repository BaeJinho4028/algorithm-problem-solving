#include <bits/stdc++.h>
using namespace std;

int mn = '????';

void d(int cur, vector<string> board, pair<int,int> r, pair<int,int> b);

void f(vector<string>& board, pair<int, int>& ball, char c, int dir, bool& rf, bool& bf) {
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };

    auto [x, y] = ball;
    board[x][y] = '.';

    while (true) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (board[nx][ny] == 'O') {
            if (c == 'R') {
                rf = true;
                return;
            }
            else {
                bf = true;
                return;
            }
        }

        if (board[nx][ny] != '.') {
            ball = {x, y};
            board[x][y] = c;
            return;
        }

        x = nx;
        y = ny;
    }
}

void bt(int cur, vector<string> board, pair<int, int> r, pair<int, int> b, int dir) {
    if (cur > 10) {
        return;
    }

    bool rf = false, bf = false;

    // 상하좌우
    if (dir == 0) {
        if (r.first > b.first) {
            f(board, b, 'B', dir, rf, bf);
            f(board, r, 'R', dir, rf, bf);
        }
        else {
            f(board, r, 'R', dir, rf, bf);
            f(board, b, 'B', dir, rf, bf);
        }
    }
    else if (dir == 1) {
        if (r.first < b.first) {
            f(board, b, 'B', dir, rf, bf);
            f(board, r, 'R', dir, rf, bf);
        }
        else {
            f(board, r, 'R', dir, rf, bf);
            f(board, b, 'B', dir, rf, bf);
        }
    }
    else if (dir == 2) {
        if (r.second > b.second) {
            f(board, b, 'B', dir, rf, bf);
            f(board, r, 'R', dir, rf ,bf);
        }
        else {
            f(board, r, 'R', dir, rf, bf);
            f(board, b, 'B', dir, rf, bf);
        }
    }
    else if (dir == 3) {
        if (r.second < b.second) {
            f(board, b, 'B', dir, rf, bf);
            f(board, r, 'R', dir, rf, bf);
        }
        else {
            f(board, r, 'R', dir, rf, bf);
            f(board, b, 'B', dir, rf, bf);
        }
    }

    if (bf) {
        return;
    }
    if (rf) {
        mn = min(mn, cur);
        return;
    }

    d(cur + 1, board, r, b);
}

void d(int cur, vector<string> board, pair<int, int> r, pair<int, int> b) {
    for (int dir = 0; dir < 4; ++dir) {
        bt(cur, board, r, b, dir);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<string> board(n);
    pair<int, int> r, b;
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 'R') {
                r = { i, j };
            }
            else if (board[i][j] == 'B') {
                b = { i, j };
            }
        }
    }

    d(1, board, r, b);
    cout << (mn == '????' ? -1 : mn);
}
