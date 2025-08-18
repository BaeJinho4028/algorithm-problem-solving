#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    string two[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};

    for (int i = 0; i < s.length(); ++i) {
        int tmp = s[i] - '0';
		if (i == 0) cout << stoi(two[tmp]);
		else cout << two[tmp];
    }
}
