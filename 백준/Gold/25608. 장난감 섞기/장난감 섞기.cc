#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
    }

    vector<int> sum(n), mxsub(n), pre(n), suf(n);

    for (int i = 0; i < n; ++i) {
        int cur = 0, mx = 0;
        for (int x : v[i]) {
            cur = max(0, cur + x);
            mx = max(mx, cur);
        }
        mxsub[i] = mx;

        int s = 0, p = 0;
        for (int x : v[i]) {
            s += x;
            p = max(p, s);
        }
        sum[i] = s;
        pre[i] = p;

        s = 0;
        p = 0;
        for (int j = m - 1; j >= 0; --j) {
            s += v[i][j];
            p = max(p, s);
        }
        suf[i] = p;
    }

    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 0);

    int ans = 0;
    do {
        int cur = 0;
        for (int idx : perm) {
            ans = max(ans, cur + pre[idx]);
            ans = max(ans, mxsub[idx]);
            cur = max(suf[idx], cur + sum[idx]);
        }
    } while (next_permutation(perm.begin(), perm.end()));

    cout << ans;
}
