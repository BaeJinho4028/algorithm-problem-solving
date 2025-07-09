#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
int unused;
const int MX = 1e6 + 5;
vector<pair<int, int>> nxt[MX];
bool en[MX];

int ans;

int get_child(int idx, char c) {
    for (auto [c_idx, c_c] : nxt[idx]) {
        if (c == c_c) {
            return c_idx;
        }
    }
    return -1;
}

void insert(string& s) {
    int cur = ROOT;
    for (char c : s) {
        int child = get_child(cur, c);
        if (child == -1) {
            child = unused;
            nxt[cur].push_back({unused++, c});
        }
        cur = child;
    }
    en[cur] = true;
}

void dfs(int cur, int cnt) {
    if (en[cur]) ans += ++cnt;
    else if (nxt[cur].size() > 1) ++cnt;

    for (auto [c_idx, _] : nxt[cur]) {
        dfs(c_idx, cnt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(2);

    int n;
    while (cin >> n) {
        for (int i = 0; i < MX; ++i) {
            nxt[i].clear();
        }
        fill(en, en + MX, false);
        unused = 2;
        ans = 0;

        vector<string> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            insert(v[i]);
        }

        for (auto [idx, _] : nxt[ROOT]) {
            dfs(idx, 0);
        }
        cout << 1.0 * ans / v.size() << '\n';
    }
}
