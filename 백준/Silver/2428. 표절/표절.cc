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

    int r = 0;
    long long ans = 0;
    for (int l = 0; l < n; ++l) {
        while (r < n && v[l] * 10 >= v[r] * 9) r++;
        ans += (r - l - 1);
    }

    cout << ans;
}
