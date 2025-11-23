#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

    
        cout << upper_bound(p.begin(), p.end(), b) - lower_bound(p.begin(), p.end(), a) << '\n';
    }
}
