#include <bits/stdc++.h>
using namespace std;

int cnt;

void dfs(int cur, const vector<int>& adj, vector<bool>& vis, vector<bool>& finished) {
    vis[cur] = true;
    int nxt = adj[cur];

    if (!vis[nxt]) {
        dfs(nxt, adj, vis, finished);
    }
    else if (!finished[nxt]) {
        cnt++;
        for (int x = nxt; x != cur; x = adj[x]) {
            cnt++;
        }
    }

    finished[cur] = true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n; 
        cin >> n;

        vector<int> adj(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> adj[i];
        }

        vector<bool> vis(n + 1, false);
        vector<bool> finished(n + 1, false);

        cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                dfs(i, adj, vis, finished);
            }
        }

        cout << n - cnt << '\n';
    }
}