#include <bits/stdc++.h>
using namespace std;

long long d[1000005];
int n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	d[1] = 1;
	d[2] = 2;
	d[3] = 4;

	for (int i = 4; i <= 1000000; i++) {
		d[i] = (d[i - 1] + d[i - 2] + d[i - 3]) % 1000000009;
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << d[n] << '\n';
	}
}
