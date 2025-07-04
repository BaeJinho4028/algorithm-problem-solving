#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
int vis = 2;
const int MX = 10 * 10000 + 5;
bool en[MX];
int child[MX][10];

bool insert(string& s) {
    int cur = ROOT;
    for (char c : s) {
        int& nxt = child[cur][c - '0'];
        if (nxt == -1) {
            nxt = vis++;
        } else if (en[nxt]) {
            return false;
        }
        cur = nxt;
    }
    if (cur != vis - 1) return 0;
    return en[cur] = true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        vis = 2;
        fill(en, en + MX, 0);
        for (int i = 0; i < MX; ++i) {
            fill(child[i], child[i] + 10, -1);
        }

        int n;
        cin >> n;
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            if (!insert(s)) flag = false;
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }
}