#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[25][25];
bool u[25][25];

int main() { //
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> d[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			bool only = true;

			for (int k = 1; k <= n; k++) {
				if (k == i || k == j) continue;
				
				int tmp = d[i][k] + d[k][j];
				if (tmp < d[i][j]) {
					cout << -1;
					return 0;
				}
				else if (tmp == d[i][j]) only = false;
			}
			if (only)  u[i][j] = u[j][i] = 1;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (u[i][j]) ans += d[i][j];

	cout << ans;
}