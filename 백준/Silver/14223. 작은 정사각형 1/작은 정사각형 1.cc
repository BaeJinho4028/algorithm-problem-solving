#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    long long ans = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            long long minX = LLONG_MAX, maxX = LLONG_MIN;
            long long minY = LLONG_MAX, maxY = LLONG_MIN;

            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;

                minX = min(minX, x[k]);
                maxX = max(maxX, x[k]);
                minY = min(minY, y[k]);
                maxY = max(maxY, y[k]);
            }

            long long side = max(maxX - minX, maxY - minY) + 2;
            ans = min(ans, side * side);
        }
    }

    cout << ans;
    return 0;
}
