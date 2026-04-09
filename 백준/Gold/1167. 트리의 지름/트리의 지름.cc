#include <bits/stdc++.h>
using namespace std;

int n;
vector<bool> vis;
vector<vector<pair<int, int>>> adj;
int node, mx;

void dfs(int x, int sum) {
    if (vis[x]) return;
    vis[x] = true;

    if (sum > mx) {
        mx = sum;
        node = x;
    }

    for (auto [nx, nw] : adj[x]) {
        dfs(nx, sum + nw);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    adj.assign(n + 1, vector<pair<int, int>>());
    for (int i = 1; i <= n; ++i) {
        int cur, nxt, w;

        cin >> cur;

        while (cin >> nxt) {
            if (nxt == -1) break;
            
            cin >> w;
            adj[cur].push_back({nxt, w});
        }
    }

    vis.assign(n + 1, false);
    dfs(1, 0);
    vis.assign(n + 1, false);
    dfs(node, 0);

    cout << mx;
}
