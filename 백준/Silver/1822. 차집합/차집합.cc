#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());

    vector<int> ans;
    for (int x : a) {
        if (!binary_search(b.begin(), b.end(), x)) {
            ans.push_back(x);
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (int x : ans) {
        cout << x << ' ';
    }
}
