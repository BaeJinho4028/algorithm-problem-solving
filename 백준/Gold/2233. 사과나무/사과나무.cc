#include <bits/stdc++.h>
using namespace std;

vector<bool> vis;
vector<int> p, d;
vector<vector<int>> adj;


void dfs(int cur, int dep, int pre) {
    vis[cur] = true;
    d[cur] = dep;
    p[cur] = pre;

    for (auto nxt : adj[cur]) {
        if (vis[nxt]) continue;
        dfs(nxt, dep + 1, cur);
    }
}

int f(int u, int v) {
    if (d[u] < d[v]) swap(u, v);

    while (d[u] != d[v]) {
        u = p[u];
    }

    while (u != v) {
        u = p[u];
        v = p[v];
    }
    return u;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vis.resize(n + 1);
    p.resize(n + 1);
    d.resize(n + 1);
    adj.assign(n + 1, vector<int>());

    string s;
    cin >> s;

    stack<int> st;
    vector<vector<int>> v(n + 1);
    vector<int> r(s.size() + 1);

    int u = 1;
    st.push(1);

    v[1].push_back(1);
    r[1] = 1;

    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == '0') {
            ++u;
            adj[u].push_back(st.top());
            adj[st.top()].push_back(u);
            st.push(u);

            v[u].push_back(i + 1);
            r[i + 1] = u;
        } else {
            v[st.top()].push_back(i + 1);
            r[i + 1] = st.top();
            
            st.pop();
        }
    }

    int x, y;
    cin >> x >> y;
    dfs(1, 0, 0);
    int tmp = f(r[x], r[y]);
    cout << v[tmp][0] << ' ' << v[tmp][1];
}

/*
5
0001011011
4 5

2 7

---

   1
2     6

3     7

4 5


lca네


0일경우
0-1연결
1-2연결
2-3연결

*/
