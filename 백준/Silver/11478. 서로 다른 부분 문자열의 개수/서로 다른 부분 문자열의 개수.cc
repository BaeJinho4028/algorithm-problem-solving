#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	set<string> se;
	for (int i = 0; i < s.size(); i++) {
		string a;
		for (int len = 1; i + len <= s.size(); len++) {
			se.insert(s.substr(i, len));
		}
	}
	cout << se.size();
}