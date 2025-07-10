#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[1002];

int solve(int st, int en) {
    vector<int> d(1002, '????');
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    d[st] = 0;
    pq.push({d[st], st});

    while(!pq.empty()) {
        auto [cw, cu] = pq.top(); pq.pop();

        if (d[cu] != cw) continue;
        for (auto [nw, nv] : adj[cu]) {
            if (d[nv] > d[cu] + nw) {
                d[nv] = d[cu] + nw;
                pq.push({d[nv], nv});
            }
        }
    }
    return d[en];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, en;
    cin >> n >> m >> en;

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    int ans = 0;
    for (int st = 1; st <= n; ++st) {
        ans = max(ans, solve(st, en) + solve(en, st));
    }
    cout << ans;
}
