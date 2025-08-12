#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<bool> ward(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ward[i] = x;
    }
    ward[n - 1] = false;

    vector<pair<long long, int>> adj[n];
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    vector<long long> d(n, LLONG_MAX / 2);
    d[0] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({d[0], 0});

    while (!pq.empty()) {
        auto [cw, cv] = pq.top(); pq.pop();
        if (cw != d[cv]) continue;

        for (auto [nw, nv] : adj[cv]) {
            if (ward[nv]) continue;
            nw += cw;
            if (d[nv] > nw) {
                d[nv] = nw;
                pq.push({nw, nv});
            }
        }
    }
    cout << (d[n - 1] == LLONG_MAX/2 ? -1 : d[n - 1]);
}
