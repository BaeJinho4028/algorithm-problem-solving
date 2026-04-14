#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v;
vector<vector<int>> d;

int f(int st, int en) {
    if (st == en) return 0;

    int& ret = d[st][en];
    if (~ret) return ret;

    ret = '????';

    for (int mid = st; mid < en; ++mid) {
        ret = min(
            ret, 
            f(st, mid) + f(mid + 1, en) + (v[st].first * v[mid].second * v[en].second)
        );
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }

    d.assign(n, vector<int>(n, -1));
    cout << f(0, n - 1);
}

