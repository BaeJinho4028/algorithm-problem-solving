#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
int vis = 2;
const int MX = 100000 * 10 + 5;
int child[MX][26];
map<string, int> ma;

void insert(string& s) {
    int cur = ROOT;
    bool flag = true;
    string tmp = "";
    for (char c : s) {
        int& nxt = child[cur][c - 'a'];
        tmp += c;
        if (nxt == -1) {
            nxt = vis++;
            if (flag) {
                cout << tmp << '\n';
                flag = false;
            }
        }
        cur = nxt;
    }
    if (flag) {
        cout << tmp << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < MX; ++i) {
        fill(child[i], child[i] + 26, -1);
    }

    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        ma[s]++;
        if (ma[s] > 1) {
            cout << s << ma[s] << '\n';
        } else {
            insert(s);
        }
    }
}
