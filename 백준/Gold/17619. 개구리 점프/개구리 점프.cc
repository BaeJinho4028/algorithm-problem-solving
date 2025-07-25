#include <bits/stdc++.h>
using namespace std;

vector<int> p(100'000, -1);

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

    int n, q;
    cin >> n >> q;
    vector<tuple<int, int, int>> e(n);
    for (int i = 0; i < n; ++i) {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        e[i] = {x1, x2, i};
    }

    sort(e.begin(), e.end());

    auto [cl, cr, ci] = e[0];
    for (int i = 1; i < n; ++i) {
        auto [nl, nr, ni] = e[i];

        if (cr >= nl) {
            uni(ci, ni);
            if (cr < nr) {
                cr = nr;
                ci = ni;
            }
        }
        else {
            cr = nr;
            ci = ni;
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (find(a - 1) == find(b - 1)) << '\n';
    }
}
