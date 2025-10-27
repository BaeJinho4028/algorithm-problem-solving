#include <bits/stdc++.h>
using namespace std;

int dfs(int u, int p, vector<vector<pair<int, int>>>& adj) {
    bool leaf = true;

    int sum = 0;
    for (auto [d, v] : adj[u]) {
        if (v == p) continue;
        leaf = false;
        int child = dfs(v, u, adj);
        sum += min(child, d);
    }

    if (leaf) return INT_MAX;
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v, d;
            cin >> u >> v >> d;
            adj[u].push_back({d, v});
            adj[v].push_back({d, u});
        }

        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }

        cout << dfs(1, -1, adj) << '\n';
    }
}
