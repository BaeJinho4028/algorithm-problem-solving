#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int m;
    cin >> m;
    while (m--) {
        int x;
        cin >> x;

        int st = 0;
        int en = n;
        while (st < en) {
            int mid = (st + en) / 2;
            if (x > v[mid]) st = mid + 1;
            else en = mid;
        }
        cout << (st < n && v[st] == x) << '\n';
    }
}
