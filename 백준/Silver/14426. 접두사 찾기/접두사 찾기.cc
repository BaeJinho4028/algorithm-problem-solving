#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
int unused = 2;
const int MX = 500 * 10000 + 5;
int tr[MX][26];
bool en[MX];

void insert(string& s) {
    int cur = ROOT;
    for (char c : s) {
        int& nxt = tr[cur][c - 'a'];
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
        int& nxt = tr[cur][c - 'a'];
        if (nxt == -1) {
            return false;
        }
        cur = nxt;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(tr, -1, sizeof(tr));

    int n, m;
    cin >> n >> m;

    while (n--) {
        string s;
        cin >> s;
        insert(s);
    }

    int cnt = 0;
    while (m--) {
        string s;
        cin >> s;
        cnt += find(s);
    }

    cout << cnt;
}
