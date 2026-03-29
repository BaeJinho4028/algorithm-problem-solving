#include <bits/stdc++.h>
using namespace std;

int k;

void f(int cur, int num, const vector<int>& v, vector<bool>& vis) {
    if (cur == k) {
        if (num > 0) {
            vis[num] = true;
        }
        return;
    }

    f(cur + 1, num, v, vis);
    f(cur + 1, num + v[cur], v, vis);
    f(cur + 1, num - v[cur], v, vis);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k;

    vector<int> v(k);
    for (int i = 0; i < k; ++i) {
        cin >> v[i];
    }

    int sum = accumulate(v.begin(), v.end(), 0);
    vector<bool> vis(sum + 1, false);

    f(0, 0, v, vis);

    int ans = 0;
    for (int i = 1; i <= sum; ++i) {
        if (!vis[i]) {
            ans++;
        }
    }

    cout << ans;
}

