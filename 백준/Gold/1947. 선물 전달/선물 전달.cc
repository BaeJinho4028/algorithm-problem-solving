#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> d(1'000'002);
    d[1] = 0;
    d[2] = 1;
    d[3] = 2;
    d[4] = 9;

    for (int i = 5; i <= n; ++i) {
        d[i] = (i - 1LL) * (d[i - 1] + d[i - 2]) % 1'000'000'000;
    }
    cout << d[n];
}
