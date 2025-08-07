#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define X first
#define Y second

vector<tuple<ll, int, int>> e;
int p[1005];
pair<int, int> xy[1005];

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool dif(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return 0;

	if (p[u] == p[v]) p[u]--;
	if (p[u] < p[v]) p[v] = u;
	else p[u] = v;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	fill(p, p + n + 1, -1);

	int x, y;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		xy[i] = { x, y };
	}

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		if (dif(x, y)) cnt++;
	}

	ll len;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int dx = xy[i].X - xy[j].X;
			int dy = xy[i].Y - xy[j].Y;
			len = (ll)dx * dx + (ll)dy * dy;
			e.push_back({ len, i, j });
		}
	}

	sort(e.begin(), e.end());

	double ans = 0;
	for (auto cur : e) {
		tie(len, x, y) = cur;
		if (!dif(x, y)) continue;
		ans += sqrt(len);
		cnt++;
		if (cnt == n - 1) break;
	}

	cout << fixed;
	cout.precision(2);
	cout << ans;
}