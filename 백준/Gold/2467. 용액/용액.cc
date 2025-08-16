#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int a = '????', b = '????';

    int st = 0;
    int en = n - 1;
    while (st < en) {
        if (abs(a + b) > abs(v[st] + v[en])) {
            a = v[st];
            b = v[en];
        }

        if (abs(v[st] + v[en - 1]) <= abs(v[st + 1] + v[en])) en = en - 1;
        else st = st + 1;
    }
    cout << a << ' ' << b;
}
