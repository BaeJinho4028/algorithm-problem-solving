#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> x(n), y(n); 
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    long long ans = LLONG_MAX;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {

            long long mnX = LLONG_MAX, mxX = LLONG_MIN;
            long long mnY = LLONG_MAX, mxY = LLONG_MIN;

            for (int k = 0; k < n; ++k) {
                if (k == i || k == j) continue;

                mnX = min(mnX, x[k]);
                mxX = max(mxX, x[k]);
                mnY = min(mnY, y[k]);
                mxY = max(mxY, y[k]);
            }
            
            long long e = max(mxX - mnX, mxY - mnY) + 2;
            ans = min(ans, e * e);
        }
    }

    cout << ans;
}
