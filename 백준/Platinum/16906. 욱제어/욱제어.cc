#include <bits/stdc++.h>
using namespace std;

bool success = true;
string ret;

const int ROOT = 1;
int unused = 2;
const int MX = 1000;
vector<vector<int>> child(MX, vector<int>(2, -1));
bool en[MX];

void insert(string& s) {
    int cur = ROOT;
    for (char c : s) {
        int& nxt = child[cur][c - '0'];
        if (nxt == -1) {
            nxt = unused++;
        }
        cur = nxt;
    }
    en[cur] = true;
}

bool find(string& s) {
    int cur = ROOT;
    for (char c : s) {
        int& nxt = child[cur][c - '0'];
        if (nxt == -1) {
            return false;
        }
        cur = nxt;
    }
    return en[cur];
}

void dfs(int len, string s) {
    if (success) return;
    if (s.size() == len) {
        insert(s);
        success = true;
        ret = s;
    }

    string nxt0 = s + '0';
    if (!find(nxt0)) dfs(len, nxt0);
    if (success) return;

    string nxt1 = s + '1';
    if (!find(nxt1)) dfs(len, nxt1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> v;
    vector<string> ans(n);

    for (int i = 0; i < n; ++i) {
        int len;
        cin >> len;
        v.push_back({len, i});
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); ++i) {
        auto [len, idx] = v[i];
        success = false;
        dfs(len, "");
        if (!success) {
            cout << -1;
            return 0;
        }
        ans[idx] = ret;
    }

    cout << 1 << '\n';
    for (string a : ans) {
        cout << a << '\n';
    }
}
