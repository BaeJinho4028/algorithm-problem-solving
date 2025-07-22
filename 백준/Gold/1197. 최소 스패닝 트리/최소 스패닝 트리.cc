#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> p(10'005, -1);

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return true;
    if (p[u] == p[v]) p[u]--;
    if (p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    tuple<int, int, int> e[100'005];
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = {w, u, v};
    }
    sort(e, e + m);

    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        auto [w, u, v] = e[i];
        if(uni(u, v)) continue;
        ans += w;
        cnt++;
        if (cnt == n - 1) break;
    }
    cout << ans;
}
