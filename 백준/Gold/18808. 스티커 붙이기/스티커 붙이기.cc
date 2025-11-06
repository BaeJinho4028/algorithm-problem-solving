#include <bits/stdc++.h>
using namespace std;

int note[42][42];
int st[12][12];
int n, m, k;
int a, b;

void rotate() {
	int tmp[12][12];

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			tmp[i][j] = st[i][j];
		}
	}

	for (int i = 0; i < b; i++) {
		for (int j = 0; j < a; j++) {
			st[i][j] = tmp[a - 1 - j][i];
		}
	}

	swap(a, b);
}

bool pastable(int x, int y) {
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (note[x + i][y + j] == 1 && st[i][j] == 1)
				return false;
		}
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (st[i][j] == 1)
				note[x + i][y + j] = 1;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	while (k--) {
		cin >> a >> b;
		for (int i = 0; i < a; i++)
			for (int j = 0; j < b; j++)
				cin >> st[i][j];

		for (int tmp = 0; tmp < 4; tmp++) {
			bool isp = false;
			for (int x = 0; x <= n - a; x++) {
				if (isp) break;
				for (int y = 0; y <= m - b; y++) {
					if (pastable(x, y)) {
						isp = true;
						break;
					}
				}
			}
			if (isp) break;

			rotate();
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cnt += note[i][j];
		}
	}

	
	cout << cnt << '\n';
}