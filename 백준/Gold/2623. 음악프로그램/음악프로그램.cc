#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    vector<int> deg(n + 1);
    while (m--) {
        int x;
        cin >> x;
        if (!x) continue;

        int pre;
        cin >> pre;
        
        for (int i = 1; i < x; ++i) {
            int cur;
            cin >> cur;
            
            adj[pre].push_back(cur);
            deg[cur]++;

            pre = cur;
        }
    }

    queue<int> q;
    vector<int> ans;

    for (int i = 1; i <= n; ++i) {
        if (!deg[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        ans.push_back(cur);

        for (int nxt : adj[cur]) {
            deg[nxt]--;
            if (!deg[nxt]) {
                q.push(nxt);
            }
        }
    }

    if (ans.size() == n) {
        for (int a : ans) {
            cout << a << '\n';
        }
    }
    else {
        cout << 0;
    }
}
