#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;
    int mn = 0;
    int sum = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (i * i >= m) {
            sum += i * i;
            if (mn == 0) {
                mn = i * i;
            }
        }
    }
    
    if (sum == 0) {
        cout << -1;
    }
    else {
        cout << sum << '\n' << mn;
    }
}
