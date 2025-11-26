#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<tuple<int, int, int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        int a, h, w;
        cin >> a >> h >> w;
        v[i] = {a, h, w, i + 1};
    }
    sort(v.begin(), v.end(), greater<>());

    vector<int> d(n), pre(n, -1);

    int mx = 0;

    for (int i = 0; i < n; ++i) {
        auto [ia, ih, iw, ii] = v[i];
        d[i] = ih;

        for (int j = 0; j < i; ++j) {
            auto [ja, jh, jw, ji] = v[j];
            if (jw > iw) {
                if (d[i] < d[j] + ih) {
                    d[i] = d[j] + ih;
                    pre[i] = j;
                }
            }
        }
        if (d[mx] < d[i]) {
            mx = i;
        }
    }

    vector<int> ans;
    while (mx != -1) {
        ans.push_back(get<3>(v[mx]));
        mx = pre[mx];
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << '\n';
    }
}
