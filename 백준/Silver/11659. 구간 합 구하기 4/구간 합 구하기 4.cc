#include <bits/stdc++.h>
using namespace std;

int d[100005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	d[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
		d[i] += d[i - 1];
	}

	
	while (m--) {
		int a, b;
		cin >> a >> b;
		
		cout << d[b] - d[a-1] << '\n';
	}
}