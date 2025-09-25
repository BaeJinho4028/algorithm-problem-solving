#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> b(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }

        vector<int> adj[n + 1];
        vector<int> deg(n + 1);
        for (int i = 0; i < k; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            deg[b]++;
        }

        queue<int> q;
        vector<int> d(n + 1);
        for (int i = 1; i <= n; ++i) {
            if (deg[i] == 0) {
                d[i] = b[i];
                q.push(i);
            }
        }

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int nxt : adj[cur]) {
                d[nxt] = max(d[nxt], d[cur] + b[nxt]);
                if (--deg[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }
        
        int w;
        cin >> w;
        cout << d[w] << '\n';
    }
}
