#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int,int>> adj[1002];
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    priority_queue<int> d[1002];
    d[1].push(0);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({d[1].top(), 1});

    while (!pq.empty()) {
        auto [cw, cv] = pq.top(); pq.pop();

        for (auto [nw, nv] : adj[cv]) {
            if (d[nv].size() < k) {
                d[nv].push(cw + nw);
                pq.push({cw + nw, nv});
            } 
            else if (d[nv].top() > cw + nw) {
                d[nv].pop();
                d[nv].push(cw + nw);
                pq.push({cw + nw, nv});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << (d[i].size() < k ? -1 : d[i].top()) << '\n';
    }
}
