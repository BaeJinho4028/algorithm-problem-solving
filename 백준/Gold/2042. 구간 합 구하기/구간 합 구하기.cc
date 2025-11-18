#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<ll> seg;

ll build(int node, int st, int en, const vector<ll>& v) {
    if (st == en) return seg[node] = v[st];
    int mid = (st + en) / 2;
    return seg[node] = build(node * 2, st, mid, v) + build(node * 2 + 1, mid + 1, en, v);
}

ll query(int node, int st, int en, int l, int r) {
    if (r < st || en < l) return 0;
    if (l <= st && en <= r) return seg[node];
    int mid = (st + en) / 2;
    return query(node * 2, st, mid, l, r) + query(node * 2 + 1, mid + 1, en, l, r);
}

void update(int node, int st, int en, int idx, ll dif) {
    if (idx < st || idx > en) return;
    seg[node] += dif;
    if (st == en) return;
    int mid = (st + en) / 2;
    update(node * 2, st, mid, idx, dif);
    update(node * 2 + 1, mid + 1, en, idx, dif);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, k;
    cin >> n >> m >> k;

    vector<ll> v(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }

    seg.assign(4 * n, 0);
    build(1, 1, n, v);

    int a, b;
    ll c;
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;

        if (a == 1) {
            ll dif = c - v[b];
            v[b] = c;
            update(1, 1, n, b, dif);
        }
        else {
            cout << query(1, 1, n, b, c) << '\n';
        }
    }
}
