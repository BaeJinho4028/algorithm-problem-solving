#include <bits/stdc++.h>
using namespace std;

bool chk (string& s) {
    if (s.size() == 0) return true;

    int h = s.size() / 2;

    string l = s.substr(0, h);
    string r = s.substr(s.size() - h, h);
    reverse(r.begin(), r.end());
    if (l != r) return false;

    return chk(l) && chk(r);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    if (chk(s)) cout << "AKARAKA";
    else cout << "IPSELENTI";
}
