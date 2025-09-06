#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> t(n + 2), p(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> t[i] >> p[i];
    }

    vector<int> d(n + 2);
    for (int i = 1; i <= n + 2; ++i) {
        d[i] = max(d[i], d[i - 1]);

        if (i + t[i] <= n + 1) {
            d[i + t[i]] = max(d[i + t[i]], d[i] + p[i]);
        }
    }
    cout << d[n + 1];
}
