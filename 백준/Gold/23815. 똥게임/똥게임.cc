#include <bits/stdc++.h>
using namespace std;

int f(string s, int cur) {
    if (cur <= 0) return -'????';

    if (s[0] == '+') {
        return cur + (s[1] - '0');
    }
    else if (s[0] == '-') {
        return cur - (s[1] - '0');
    }
    else if (s[0] == '*') {
        return cur * (s[1] - '0');
    }
    return cur / (s[1] - '0');
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> d(n + 1, vector<int>(2));
    d[0][0] = 1;

    int mn = 1;
    for (int i = 1; i <= n; ++i) {
        string a, b;
        cin >> a >> b;

        d[i][0] = max(f(a, d[i - 1][0]), f(b, d[i - 1][0]));
        d[i][1] = max({d[i - 1][0], f(a, d[i - 1][1]), f(b, d[i - 1][1])});
    }

    int ans = max(d[n][0], d[n][1]);
    if (ans <= 0) cout << "ddong game";
    else cout << max(d[n][0], d[n][1]);
}
