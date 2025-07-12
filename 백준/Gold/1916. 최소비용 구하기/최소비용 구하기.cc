#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> adj[n + 1];
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    int st, en;
    cin >> st >> en;

    vector<int> d(n + 1, '????');
    d[st] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({d[st], st});

    while (!pq.empty()) {
        auto [cw, cv] = pq.top(); pq.pop();

        if (d[cv] != cw) continue;
        for (auto [nw, nv] : adj[cv]) {
            if (d[nv] > d[cv] + nw) {
                d[nv] = d[cv] + nw;
                pq.push({d[nv], nv});
            }
        }
    }
    cout << d[en];
}
