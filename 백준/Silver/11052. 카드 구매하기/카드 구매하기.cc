#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> d(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            d[i] = max(d[i], d[i - j] + d[j]);
        }
    }
    cout << d[n];
}
