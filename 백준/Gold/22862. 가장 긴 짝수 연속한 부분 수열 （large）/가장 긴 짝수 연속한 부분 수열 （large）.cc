#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int st = 0, en = 0, cnt = 0, ans = 0;;
    while (en < n) {
        if (v[en++] % 2 != 0) {
            cnt++;
        }

        while (cnt > k) {
            if (v[st++] % 2 != 0) {
                cnt--;
            }
        }

        ans = max(ans, (en - st) - cnt);
    }
    cout << ans;
}
