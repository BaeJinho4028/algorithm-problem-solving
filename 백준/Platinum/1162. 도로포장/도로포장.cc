#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<tuple<ll, int, int>> adj[10002];
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, 0, v});
        adj[u].push_back({0, 1, v});
        adj[v].push_back({w, 0, u});
        adj[v].push_back({0, 1, u});
    }

    vector<vector<ll>> d(22, vector<ll>(10002, LLONG_MAX));
    for (int i = 0; i <= k; ++i) {
        d[i][1] = 0;
    }

    priority_queue<tuple<ll, int, int>, 
        vector<tuple<ll, int, int>>, 
        greater<tuple<ll, int, int>>> pq;
    pq.push({0, 0, 1});

    while (!pq.empty()) {
        auto [cw, ck, cv] = pq.top(); pq.pop();
        if (d[ck][cv] != cw) continue;

        for (auto [nw, nk, nv] : adj[cv]) {
            nk += ck;
            if (nk > k) continue;

            nw += cw;
            if (d[nk][nv] > nw) {
                d[nk][nv] = nw;
                pq.push({nw, nk, nv});
            }
        }
    }

    ll ans = LLONG_MAX;
    for (int i = 0; i <= k; ++i) {
        ans = min(ans, d[i][n]);
    }
    cout << ans;
}
