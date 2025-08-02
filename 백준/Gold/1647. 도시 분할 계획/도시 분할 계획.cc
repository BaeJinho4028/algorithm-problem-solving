#include <bits/stdc++.h>
using namespace std;

vector<int> p(100'002, -1);

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return true;
    p[u] = v;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> e(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = {w, u, v};
    }
    sort(e.begin(), e.end());

    int ans = 0;
    int cnt = 0;
    int mx = 0;
    for (auto [w, u, v] : e) {
        if (!uni(u, v)) {
            ans += w;
            mx = w;
            cnt++;
        }

        if (cnt == n - 1) break;
    }

    cout << ans - mx;
}
