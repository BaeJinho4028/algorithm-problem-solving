#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.size();
    int k = count(s.begin(), s.end(), 'a');
    int b = count(s.begin(), s.begin() + k, 'b');

    s = s + s;
    int ans = b;
    for (int i = k; i < n * 2; ++i) {
        if (s[i] == 'b') b++;
        if (s[i - k] == 'b') b--;
        ans = min(ans, b);
    }

    cout << ans;
}
