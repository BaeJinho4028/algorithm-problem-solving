#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    int b;
    cin >> n >> b;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    const char az[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ans;

    while (n > 0) {
        int rem = n % b;
        ans.push_back(az[rem]);
        n /= b;
    }
    reverse(ans.begin(), ans.end());

    cout << ans << '\n';
    return 0;
}
