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
    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int st = 0, en = n - 1;

        while (st < en) {
            int sum = v[st] + v[en];

            if (sum == v[i]) {
                if (i == st) st++;
                else if (i == en) en--;
                else break;
            }
            else if (sum > v[i]) en--;
            else st++;
        }
        ans += st < en;
    }
    cout << ans;
}
