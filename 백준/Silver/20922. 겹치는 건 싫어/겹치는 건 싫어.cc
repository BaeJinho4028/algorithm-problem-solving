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

    int st = 0, en = 0, ans = 0;
    vector<int> chk(200'002);
    while (st < n) {
        while (en < n && chk[v[en]] < k) {
            chk[v[en++]]++;
        }
        ans = max(ans, en - st);
        chk[v[st++]]--;
    }
    cout << ans;
}
