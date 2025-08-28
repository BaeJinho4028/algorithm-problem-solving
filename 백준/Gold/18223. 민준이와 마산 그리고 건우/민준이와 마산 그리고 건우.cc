#include <bits/stdc++.h>
using namespace std;

int v, e, p;
vector<vector<pair<int, int>>> adj(5'002);

int dijkstra(int a, int b) {
    vector<int> d(v + 1, '????');
    d[a] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, a});

    while (!pq.empty()) {
        auto [cc, ca] = pq.top();
        pq.pop();

        if (d[ca] != cc) continue;
        for (auto [nc, na] : adj[ca]) {
            nc += cc;
            if (d[na] > nc) {
                d[na] = nc;
                pq.push({nc, na});
            }
        }
    }
    return d[b];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e >> p;

    while (e--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    cout << (dijkstra(1, p) + dijkstra(p, v) == dijkstra(1, v) ? "SAVE HIM" : "GOOD BYE");
}
