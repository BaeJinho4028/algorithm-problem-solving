#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();

    int k = count(s.begin(), s.end(), 'a');
    if (k == 0 || k == n) {
        cout << 0 << '\n';
        return 0;
    }

    s = s + s;

    int b = 0;
    for (int i = 0; i < k; ++i) {
        if (s[i] == 'b') {
            b++;
        }
    }

    int ans = b;
    for (int i = 1; i < n; ++i) {
        if (s[i - 1] == 'b') b--;
        if (s[i + k - 1] == 'b') b++;
        ans = min(ans, b);
    }

    cout << ans;
}
