#include <bits/stdc++.h>
using namespace std;

vector<int> p(1'000'002, -1);

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

    vector<pair<int, int>> v;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    int ans = 0;
    int x = 0, y = 0;
    for (int i = 0; i < m; ++i) {
        auto [nx, ny] = v[i];
        if (y < nx) {
            ans += nx - y;
        }
        y = max(y, ny);
    }
    ans += n - y;
    cout << ans;
}
