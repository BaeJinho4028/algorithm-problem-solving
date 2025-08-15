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

    int st = 1;
    int en = *max_element(v.begin(), v.end());
    while (st <= en) {
        long long mid = st + en >> 1;

        long long chk = 0;
        for (int i = 0; i < n; ++i) {
            chk += max(0LL, v[i] - mid);
        }

        if (chk >= m) st = mid + 1;
        else en = mid - 1;
    }
    cout << en;
}
