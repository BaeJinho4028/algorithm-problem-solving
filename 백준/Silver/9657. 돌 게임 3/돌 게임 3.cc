#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<bool> d(n + 1);
    d[1] = d[3] = d[4] = true;

    for (int i = 5; i <= n; ++i) {
        if (!d[i - 1] || !d[i - 3] || !d[i - 4]) d[i] = true;
        else d[i] = false;
    }
    cout << (d[n] ? "SK" : "CY");
}
