#include <bits/stdc++.h>
using namespace std;

vector<int> compress(vector<int>& v) {
    vector<int> uni(v.begin(), v.end());
    sort(uni.begin(), uni.end());
    uni.erase(unique(uni.begin(), uni.end()), uni.end());
    for (int i = 0 ; i < v.size(); ++i) {
        v[i] = lower_bound(uni.begin(), uni.end(), v[i]) - uni.begin();
    }
    return v;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        vector<int> tmp(m);
        for (int j = 0; j < m; ++j) {
            cin >> tmp[j];
        }
        v[i] = compress(tmp);
    }

    int ans = 0;
    for (int a = 0; a < n; ++a) {
        for (int b = a + 1; b < n; ++b) {
            bool flag = true;
            for (int i = 0; i < m; ++i) {
                if (v[a][i] != v[b][i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans++;
            }
        }
    }

    cout << ans;
}
