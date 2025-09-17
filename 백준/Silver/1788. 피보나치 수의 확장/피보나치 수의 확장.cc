#include <bits/stdc++.h>
using namespace std;

int d[1000005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	d[0] = 0;
	d[1] = 1;

	if (n >= 0) {
		for (int i = 2; i <= n; i++)
			d[i] = (d[i - 1] + d[i - 2]) % 1000000000;
	}
	else {
		n = abs(n);

		for (int i = 2; i <= n; i++)
			d[i] = (d[i - 2] - d[i - 1]) % 1000000000;
	}

	if (d[n] > 0) cout << "1\n";
	else if (d[n] < 0) cout << "-1\n";
	else cout << "0\n";
	cout << abs(d[n]);
} //0 -1 -2 //0 1 -1       -1 -2 -3     1 -1 2