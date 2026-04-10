#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	list<char> l;

	int n;
	cin >> n;

	string s;

	for (int i = 0; i < n; i++) {
		cin >> s;
		l.clear();
		auto cursor = l.begin();
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == '-') {
				if (cursor != l.begin()) {
					cursor--;
					cursor = l.erase(cursor);
				}
			}
			else if (s[j] == '<') {
				if (cursor != l.begin()) cursor--;
			}
			else if (s[j] == '>') {
				if (cursor != l.end()) cursor++;
			}
			else {
				l.insert(cursor, s[j]);
			}
		}
		for (auto c : l) cout << c;
		cout << '\n';
	}
}