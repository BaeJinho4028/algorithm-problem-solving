#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> t(n + 1);
    vector<int> adj[n + 1];
    vector<int> deg(n + 1);
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> t[i] >> a;

        while (a--) {
            int b;
            cin >> b;
            adj[b].push_back(i);
            deg[i]++;
        }
    }

    queue<int> q;
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 0) {
            q.push(i);
        }
        ans[i] = t[i];
    }

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int nxt : adj[cur]) {
            deg[nxt]--;
            ans[nxt] = max(ans[nxt], ans[cur] + t[nxt]);
            if (deg[nxt] == 0) {
                q.push(nxt);
            }
        }
    }

    cout << *max_element(ans.begin(), ans.end());
}
