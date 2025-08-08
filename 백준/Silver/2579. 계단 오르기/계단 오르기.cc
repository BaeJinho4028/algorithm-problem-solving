#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> d(n + 1), s(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }

    d[1] = s[1];
    d[2] = d[1] + s[2];
    d[3] = max(s[1], s[2]) + s[3];
    for (int i = 4; i <= n; ++i) {
        d[i] = max(d[i - 3] + s[i - 1], d[i - 2]) + s[i];
    }
    cout << d[n];
}
