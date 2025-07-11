#include <bits/stdc++.h>
using namespace std;

int n, e;
vector<pair<int,int>> adj[802];

long long solve(int st, int en) {
    vector<int> d(802, '????');
    d[st] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({d[st], st});

    while(!pq.empty()) {
        auto [cw, cv] = pq.top(); pq.pop();
        
        if (d[cv] != cw) continue;
        for (auto [nw, nv] : adj[cv]) {
            if (d[nv] > d[cv] + nw) {
                d[nv] = d[cv] + nw;
                pq.push({d[nv], nv});
            }
        }
    }
    return d[en];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> e;

    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    int v1, v2;
    cin >> v1 >> v2;

    long long ans1 = solve(1, v1) + solve(v1, v2) + solve(v2, n);
    long long ans2 = solve(1, v2) + solve(v2, v1) + solve(v1, n);
    long long ans = min(ans1, ans2);
    cout << (ans >= '????' ? -1 : ans);
}
