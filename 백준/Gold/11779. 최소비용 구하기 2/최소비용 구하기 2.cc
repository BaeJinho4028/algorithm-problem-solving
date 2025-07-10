#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> d(1001, '????');
    vector<pair<int, int>> adj[1001];
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    int st, en;
    cin >> st >> en;

    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push({0, st});
    d[st] = 0;

    vector<int> pre(1001);
    while (!pq.empty()) {
        auto [cw, cu] = pq.top(); pq.pop();

        if (d[cu] != cw) continue;
        for (auto [nw, nv] : adj[cu]) {
            if (d[nv] <= d[cu] + nw) continue;
            d[nv] = d[cu] + nw;
            pq.push({d[nv], nv});
            pre[nv] = cu;
        }
    }

    cout << d[en] << '\n';

    vector<int> path;
    int cur = en;
    while (cur != 0) {
        path.push_back(cur);
        cur = pre[cur];
    }
    reverse(path.begin(), path.end());
    cout << path.size() << '\n';
    for (int p : path) {
        cout << p << ' ';
    }
}
