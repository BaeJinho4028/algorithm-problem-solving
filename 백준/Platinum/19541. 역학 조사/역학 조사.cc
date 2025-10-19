#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> p(n + 1);
    vector<int> g[m];

    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            g[i].push_back(x);
        }
    }

    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    // 한명이라도 감염 안되어있으면 모두 초기 감염 아님
    vector<int> st = p;
    for (int i = m - 1; i >= 0; --i) {
        bool flag = false;
        for (int x : g[i]) {
            if (!st[x]) {
                flag = true;
                break;
            }
        }
        if (flag) {
            for (int x : g[i]) {
                st[x] = 0;
            }
        }
    }

    // 한명이라도 있으면 모두 감염
    vector<int> chk = st;
    for (int i = 0; i < m; ++i) {
        bool flag = false;
        for (int x : g[i]) {
            if (chk[x]) flag = true;
        }
        if (flag) {
            for (int x : g[i]) {
                chk[x] = 1;
            }
        }
    }

    if (chk == p) { 
        cout << "YES\n";
        for (int i = 1; i <= n; ++i) { 
            cout << st[i] << ' '; 
        } 
    } 
    else { 
        cout << "NO\n"; 
    }
}
