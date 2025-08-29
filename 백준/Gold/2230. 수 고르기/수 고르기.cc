#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int mn = INT_MAX;
    int st = 0, en = 0;
    while (st <= en && en < n) {
        int tmp = v[en] - v[st];
        if (tmp >= m) {
            mn = min(mn, tmp);
            st++;
        }
        else {
            en++;
        }
    }
    cout << mn;
}
