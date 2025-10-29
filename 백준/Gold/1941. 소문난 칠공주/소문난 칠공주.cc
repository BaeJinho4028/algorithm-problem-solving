#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
bool mask[25];
string board[5];
int ans;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++)
		cin >> board[i];

	fill(mask + 7, mask + 25, true);

	do {
		queue<pair<int, int>> q;
		int dasom = 0, adj = 0;
		bool isp7[5][5] = {}, vis[5][5] = {};
		for (int i = 0; i < 25; i++) {
			if (!mask[i]) {
				int x = i / 5, y = i % 5;
				isp7[x][y] = true;
				if (q.empty()) {
					q.push({ x,y });
					vis[x][y] = true;
				}
			}
		}

		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			adj++;
			if (board[cur.X][cur.Y] == 'S') dasom++;
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || vis[nx][ny] || !isp7[nx][ny]) continue;
				q.push({ nx, ny });
				vis[nx][ny] = true;
			}
		}
		if(adj >= 7 && dasom >= 4) ans++;
	} while (next_permutation(mask, mask + 25));
	cout << ans;
}
