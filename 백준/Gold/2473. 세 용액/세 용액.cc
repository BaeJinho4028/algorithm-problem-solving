#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    long long sum = LLONG_MAX;

    long long ans[3];

    for (int i = 0; i < n; ++i) {
        int st = i + 1;
        int en = n - 1;
        while (st < en) {
            long long tmp = v[i] + v[st] + v[en];
            if (abs(sum) > abs(tmp)) {
                sum = tmp;
                ans[0] = v[i];
                ans[1] = v[st];
                ans[2] = v[en];
            }

            if (tmp < 0) st++;
            else en--;
        }
    }

    sort(ans, ans + 3);
    for (long long a : ans) {
        cout << a << ' ';
    }
}
