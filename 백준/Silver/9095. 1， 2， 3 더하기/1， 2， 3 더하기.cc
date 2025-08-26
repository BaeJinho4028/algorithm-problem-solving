#include <bits/stdc++.h>
using namespace std;

int d[14]; //가지수
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	for (int i = 4; i <= 11; i++) {
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	}

	while (t--) {
		int a;
		cin >> a;
		cout << d[a] << '\n';
	}
}
