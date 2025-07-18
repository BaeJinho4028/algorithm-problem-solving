#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int MX = 100'002;

vector<int> p(MX, -1);
pair<int, int> x[MX];
pair<int, int> y[MX];
pair<int, int> z[MX];

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return true;

    if (p[u] > p[v]) swap(u, v);
    p[u] += p[v];
    p[v] = u;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int cx, cy, cz;
        cin >> cx >> cy >> cz;
        x[i] = {cx, i};
        y[i] = {cy, i};
        z[i] = {cz, i};
    }

    sort(x, x + n);
    sort(y, y + n);
    sort(z, z + n);

    vector<tuple<int, int, int>> e;
    for (int i = 1; i < n; ++i) {
        e.push_back({abs(x[i - 1].X - x[i].X), x[i - 1].Y, x[i].Y});
        e.push_back({abs(y[i - 1].X - y[i].X), y[i - 1].Y, y[i].Y});
        e.push_back({abs(z[i - 1].X - z[i].X), z[i - 1].Y, z[i].Y});

    }

    sort(e.begin(), e.end());

    int cnt = 0, sum = 0;
    for (auto [w, u, v] : e) {
        if (uni(u, v)) continue;
        sum += w;
        if (++cnt == n - 1) break;
    }
    cout << sum;
}
