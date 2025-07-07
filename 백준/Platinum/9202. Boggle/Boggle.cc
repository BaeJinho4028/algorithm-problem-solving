#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
int unused = 2;
const int MX = 300000 * 8 + 5;
int child[MX][26];
int en[MX];
int turn = 2;

char board[4][4];
bool vis[4][4];
int dx[8] = { 1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = { 1, 0, -1, 1, -1, 1, 0, -1};

int score[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};
int point = 0, cnt = 0;
string mx_str = "";

void insert(string& s) {
    int cur = ROOT;
    for (char c : s) {
        int& nxt = child[cur][c - 'A'];
        if (nxt == -1) {
            nxt = unused++;
        }
        cur = nxt;
    }
    en[cur] = true;
}

void find(int x, int y, int cur, string s) {
    if (cur == -1) return;

    if (en[cur] != 0 && en[cur] != turn) {
        en[cur] = turn;
        point += score[s.size()];
        cnt++;

        if (s.size() > mx_str.size()) mx_str = s;
        else if (s.size() == mx_str.size()) mx_str = min(mx_str, s); 
    }

    for (int dir = 0; dir < 8; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
        if (vis[nx][ny]) continue;

        char c = board[nx][ny];
        vis[nx][ny] = true;
        find(nx, ny, child[cur][c - 'A'], s + c);
        vis[nx][ny] = false;
    }
}

void solve() {
    point = 0;
    cnt = 0;
    mx_str = "";

    for (int x = 0; x < 4; ++x) {
        for (int y = 0; y < 4; ++y) {
            vis[x][y] = true;
            find(x, y, child[ROOT][board[x][y] - 'A'], string(1, board[x][y]));
            vis[x][y] = false;
        }
    }
    cout << point << ' ' << mx_str << ' ' << cnt << '\n';
    turn++; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < MX; i++) {
        fill(child[i], child[i] + 26, -1);
    }

    int w;
    cin >> w;
    for (int i = 0; i < w; ++i) {
        string s;
        cin >> s;
        insert(s);
    }

    int b;
    cin >> b;
    while (b--) {
        for (int i = 0; i < 4; ++i) {
            cin >> board[i];
        }
        solve();
    }
}
