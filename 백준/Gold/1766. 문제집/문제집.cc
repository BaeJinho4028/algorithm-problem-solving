#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> deg(n + 1), adj[n + 1];
    while (m--) {
        int a, b;
        cin >> a >> b;
        deg[b]++;
        adj[a].push_back(b);
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int cur = pq.top(); pq.pop();
        cout << cur << ' ';
        for (int nxt : adj[cur]) {
            deg[nxt]--;
            if (deg[nxt] == 0) {
                pq.push(nxt);
            }
        }
    }
}
