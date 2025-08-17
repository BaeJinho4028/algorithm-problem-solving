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

    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            sum += upper_bound(v.begin() + j + 1, v.end(), -(v[i] + v[j])) - lower_bound(v.begin() + j + 1, v.end(), -(v[i] + v[j]));
        }
    }
    cout << sum;
}
