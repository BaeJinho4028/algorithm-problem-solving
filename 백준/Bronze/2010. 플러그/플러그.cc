#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = - n + 1;
    while (n--) {
        int x;
        cin >> x;
        ans += x;
    }
    cout << ans;
}
