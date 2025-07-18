#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<ll, int>> adj[n + 1];
    while (m--) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[v].push_back({w, u});
    }

    vector<ll> d(n + 1, LLONG_MAX);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    while (k--) {
        int x;
        cin >> x;
        d[x] = 0;
        pq.push({d[x], x});
    }
    
    while (!pq.empty()) {
        auto [cw, cv] = pq.top(); pq.pop();
        if (d[cv] != cw) continue;

        for (auto [nw, nv] : adj[cv]) {
            nw += cw;
            if (d[nv] > nw) {
                d[nv] = nw;
                pq.push({d[nv], nv});
            }
        }
    }

    int idx = max_element(d.begin() + 1, d.end()) - d.begin();
    cout << idx << '\n' << d[idx];
}
