#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, c;
    cin >> n >> c;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int st = 1, en = 1'000'000'000;
    while (st <= en) {
        int mid = (st + en) / 2;

        int cnt = 1, pos = v[0];

        for (int i = 1; i < n; ++i) {
            if (pos + mid <= v[i]) {
                cnt++;
                pos = v[i];
            }
        }

        if (cnt >= c) st = mid + 1;
        else en = mid - 1;
    }
    cout << en;
}
