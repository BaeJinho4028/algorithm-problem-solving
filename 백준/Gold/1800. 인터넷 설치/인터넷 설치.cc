#include <bits/stdc++.h>
using namespace std;

int n, p, k;
vector<vector<pair<int, int>>> adj;

bool f(int limit) {
    vector<int> dist(n + 1, '????');
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty()) {
        auto [cw, cv] = pq.top();
        pq.pop();

        if (cw > dist[cv]) continue;
        for (auto [nw, nv] : adj[cv]) {
            int tmp = cw + (nw > limit);
            if (dist[nv] > tmp) {
                dist[nv] = tmp;
                pq.push({tmp, nv});
            }
        }
    }

    return dist[n] <= k;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> p >> k;
    adj.resize(n + 1);

    for (int i = 0; i < p; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    int st = 0, en = 1'000'000, ans = -1;
    while (st <= en) {
        int mid = (st + en) / 2;
        if (f(mid)) {
            ans = mid;
            en = mid - 1;
        } else {
            st = mid + 1;
        }
    }

    cout << ans;
}
