#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    int a, b;
    cin >> a >> b;

    int x;
    cin >> x;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<>());

    int mx = x / a;

    for (int i = 0; i < n; ++i) {
        a += b;
        x += v[i];

        mx = max(mx, x / a);
    }

    cout << mx;
}
