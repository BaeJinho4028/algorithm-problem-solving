#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int st = 1;
    int en = *max_element(v.begin(), v.end());
    while (st <= en) {
        int mid = st + en >> 1;
        
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += v[i] / mid;
        }
        
        if (cnt >= m) st = mid + 1;
        else en = mid - 1;
    }
    cout << en;
}
