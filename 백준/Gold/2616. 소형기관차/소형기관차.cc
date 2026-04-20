#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a(50'005);
vector<vector<int>> d(4, vector<int>(50'005, -1));

int f(int cnt, int cur) {
    if (cnt == 3 || n < cur) return 0;

    int& ret = d[cnt][cur];
    if (~ret) return ret;

    ret = 0;
    ret = max(f(cnt, cur + 1), f(cnt + 1, cur + m) + (a[cur] - a[cur - m]));

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    cin >> m;

    cout << f(0, m);
}

