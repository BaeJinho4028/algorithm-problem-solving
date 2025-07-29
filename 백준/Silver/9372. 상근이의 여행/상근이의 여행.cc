#include <bits/stdc++.h>
using namespace std;

int n, m;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m;

		int a, b;
		for (int i = 0; i < m; i++)
			cin >> a >> b;

		cout << n - 1 << '\n';
	}
}