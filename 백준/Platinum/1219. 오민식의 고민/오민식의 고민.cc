#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll NEG = -(1LL << 60);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, st, en, m;
    cin >> n >> st >> en >> m;

    vector<tuple<int, int, int>> e;
    vector<vector<int>> adj(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        e.push_back({u, v, w});
        adj[u].push_back(v);
    }

    vector<int> earn(n);
    for (int i = 0; i < n; ++i) cin >> earn[i];

    vector<ll> dist(n, NEG);
    dist[st] = earn[st];

    vector<int> cycle;

    for (int i = 0; i < n; ++i) {
        for (auto [cur, nxt, w] : e) {
            if (dist[cur] == NEG) continue;

            ll nw = dist[cur] - w + earn[nxt];

            if (dist[nxt] < nw) {
                dist[nxt] = nw;
                if (i == n - 1) cycle.push_back(nxt);
            }
        }
    }

    if (dist[en] == NEG) {
        cout << "gg";
        return 0;
    }

    vector<int> vis(n, 0);
    queue<int> q;

    for (int x : cycle) {
        if (vis[x]) continue;
        vis[x] = 1;
        q.push(x);
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : adj[cur]) {
            if (vis[nxt]) continue;
            vis[nxt] = 1;
            q.push(nxt);
        }
    }

    if (vis[en]) cout << "Gee";
    else cout << dist[en];
}