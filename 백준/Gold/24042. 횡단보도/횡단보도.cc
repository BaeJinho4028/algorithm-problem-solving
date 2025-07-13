#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[100002];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({i, v});
        adj[v].push_back({i, u});
    }

    vector<ll> d(100'002, LLONG_MAX);
    d[1] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({d[1], 1});

    while (!pq.empty()) {
        auto [cw, cv] = pq.top(); pq.pop();
        if (d[cv] != cw) continue;

        for (auto [nw, nv] : adj[cv]) {
            ll nm = (nw - cw) % m;
            if (nm < 0) nm += m;
            nm += cw + 1;
            if (d[nv] > nm) {
                d[nv] = nm;
                pq.push({d[nv], nv});
            }
        }
    }
    cout << d[n];
}
