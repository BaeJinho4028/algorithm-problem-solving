#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int m = ~n + 1;

    int cnt = 0;
    for (int i = 0; i < 32; ++i) {
        if((n & 1) != (m & 1)) {
            cnt++;
        }
        n >>= 1;
        m >>= 1;
    }
    cout << cnt;
    return 0;
}
