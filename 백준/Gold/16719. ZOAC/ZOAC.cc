#include <bits/stdc++.h>
using namespace std;

string s;

void solve(int st, int en, string& tmp) {
    if (st == en) return;

    int pos = min_element(s.begin() + st, s.begin() + en) - s.begin();
    tmp[pos] = s[pos];

    for (int i = 0; i < tmp.size(); i++) {
        if (tmp[i]) cout << tmp[i];
    }
    cout << '\n';
    
    solve(pos + 1, en, tmp);
    solve(st, pos, tmp);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    
    string tmp(s.size(), 0);
    solve(0, s.size(), tmp);
}
