#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> d(n + 1);
    d[1] = 1, d[2] = 2;

    for (int i = 3; i <= n; ++i) {
        d[i] = (d[i - 1] + d[i - 2]) % 10'007;
    }

    cout << d[n];
}
