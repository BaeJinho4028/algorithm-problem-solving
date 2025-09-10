#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[11][11];
bool vis[11][11];
int island[7][5];
int num;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<int> p(7, -1);
vector<tuple<int, int, int>> e;

vector<int> adj[7];

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return true;
    p[u] = v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    return false;
}

void distance(int cur, int x, int y) {
    for (int dir = 0; dir < 4; ++dir) {

        int dist = 0;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        while (true) {
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
            if (board[nx][ny] == cur) break;

            if (board[nx][ny] != 0) {
                e.push_back({dist, cur, board[nx][ny]});
                break;
            }
            dist++;
            nx += dx[dir];
            ny += dy[dir];
        }
    }
}

void bfs(int x, int y) {
    num++;
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        board[x][y] = num;
        island[num][0] = min(island[num][0], x);
        island[num][1] = max(island[num][1], x);
        island[num][2] = min(island[num][2], y);
        island[num][3] = max(island[num][3], y);


        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] != 1) continue;
            if (vis[nx][ny]) continue;

            q.push({nx, ny});
            vis[nx][ny] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] != 0 && !vis[i][j]) {
                bfs(i, j);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] != 0) {
                distance(board[i][j], i, j);
            }
        }
    }
    sort(e.begin(), e.end());

    int ans = 0;
    for (auto [w, u, v] : e) {
        if (w < 2) continue;

        if (!uni(u, v)) {
            ans += w;
        }
    }

    int cnt = 1;
    queue<int> q;
    q.push(1);

    vector<bool> chk(7, false);
    chk[1] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (auto nxt : adj[cur]) {
            if (!chk[nxt]) {
                q.push(nxt);
                chk[nxt] = true;
                cnt++;
            }
        }
    }

    cout << (cnt == num ? ans : -1);
}
