#include <bits/stdc++.h>
using namespace std;

bool chk = false;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> p(n), s(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        c[i] = i;
    }

    set<vector<int>> vis;
    int cnt = 0;
    
    while (true) {
        bool chk = true;
        for (int i = 0; i < n; ++i) {
            if (p[c[i]] != i % 3) {
                chk = false;
                break;
            }
        }
        if (chk) {
            cout << cnt;
            return 0;
        }

        if (vis.count(c)) {
            cout << -1;
            return 0;
        }
        vis.insert(c);

        vector<int> nxt(n);
        for (int i = 0; i < n; ++i) {
            nxt[s[i]] = c[i];
        }
        c = nxt;
        cnt++;
    }
}