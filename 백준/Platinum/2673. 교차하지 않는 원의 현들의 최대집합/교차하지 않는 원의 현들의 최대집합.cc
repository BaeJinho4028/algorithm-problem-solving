#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> ma;
vector<vector<int>> d;

int f(int l, int r) {
    if (l >= r) return 0;

    int& ret = d[l][r];
    if (~ret) return ret;

    ret = f(l + 1, r - 1) + ma[{l, r}];
    for (int i = l + 1; i < r; ++i) {
        ret = max(ret, f(l, i) + f(i + 1, r));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        ma[{a, b}] = 1;
    }

    d.assign(101, vector<int>(101, -1));

    cout << f(1, 100);
}
