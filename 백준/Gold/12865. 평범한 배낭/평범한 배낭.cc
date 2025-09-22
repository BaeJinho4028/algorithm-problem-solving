#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> d(k + 1);
    for (int i = 0; i < n; ++i) {
        int w, v;
        cin >> w >> v;
        for (int j = k; j >= w; --j) {
            d[j] = max(d[j], d[j - w] + v);
        }
    }

    cout << d[k];
}
