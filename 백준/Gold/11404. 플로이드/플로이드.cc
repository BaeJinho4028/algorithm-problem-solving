#include <bits/stdc++.h>
using namespace std;

int n, m;
int city[105][105];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			city[i][j] = 0x3f3f3f3f;

	for (int i = 1; i <= m; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;

		city[a][b] = min(city[a][b], cost);
	}

	for (int i = 1; i <= n; i++) city[i][i] = 0;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (city[i][j] == 0x3f3f3f3f) cout << "0 ";
			else cout << city[i][j] << ' ';
		}
		cout << '\n';
	}
}