#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[2002];

vector<int> dijkstra(int st) {
    vector<int> d(2002, '????');
    d[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push({d[st], st});

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
    return d;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, m, t;
        cin >> n >> m >> t;

        int s, g, h;
        cin >> s >> g >> h;

        int gh = '????';

        for (int i = 1; i <= n; ++i) adj[i].clear();

        while (m--) {
            int a, b, d;
            cin >> a >> b >> d;
            adj[a].push_back({d, b});
            adj[b].push_back({d, a});
            if ((a == g && b == h) || (a == h && b == g)) {
                gh = d;
            }
        }

        vector<int> ans;
        for (int i = 0; i < t; ++i) {
            int x; cin >> x;
            ans.push_back(x);
        }
        sort(ans.begin(), ans.end());

        vector<int> ds = dijkstra(s);
        vector<int> dg = dijkstra(g);
        vector<int> dh = dijkstra(h);

        for (int x : ans) {
            int path1 = ds[g] + gh + dh[x];
            int path2 = ds[h] + gh + dg[x];
            if (ds[x] == path1 || ds[x] == path2) {
                cout << x << ' ';
            }
        }
        cout << '\n';
    }
}
