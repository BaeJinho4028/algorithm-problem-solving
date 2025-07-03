#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
int idx = 2;
const int MX = 10000 * 500 + 5;
bool en[MX];
int child[MX][26];

void insert(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        int& nxt = child[cur][c - 'a'];
        if (nxt == -1) {
            nxt = idx++;
        }
        cur = nxt;
    }
    en[cur] = true;
}

bool count(string&s) {
    int cur = ROOT;
    for (auto c : s) {
        int& nxt = child[cur][c - 'a'];
        if (nxt == -1) {
            return 0;
        }
        cur = nxt;
    }
    return 1;
}

bool find(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        int& nxt = child[cur][c - 'a'];
        if (nxt == -1) {
            return false;
        }
        cur = nxt;
    }
    return en[cur];
}

void erase(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        int& nxt = child[cur][c - 'a'];
        if (nxt == -1) {
            return;
        }
        cur = nxt;
    }
    en[cur] = false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < MX; ++i) {
        fill(child[i], child[i] + 26, -1);
    }

    while (n--) {
        string s;
        cin >> s;
        insert(s);
    }

    int ans = 0;
    while (m--) {
        string s;
        cin >> s;
        ans += count(s);
    }
    cout << ans;
    
    return 0;
}
