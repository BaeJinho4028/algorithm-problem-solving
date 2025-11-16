#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    long long sum = 0;
    long long pre = 0;
    for (int i = n - 1; i >= 0; --i) {
        pre = min(v[i], pre + 1);
        sum += pre;
    }
    cout << sum;
}