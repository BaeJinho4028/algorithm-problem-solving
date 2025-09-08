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

    vector<bool> chk(100'001, false);

    long long ans = 0;

    int st = 0, en = 0;
    while (st < n) {
        while (en < n && !chk[v[en]]) {
            chk[v[en++]] = true;
        }
        ans += (en - st);
        chk[v[st++]] = false;
    }

    cout << ans;
}
