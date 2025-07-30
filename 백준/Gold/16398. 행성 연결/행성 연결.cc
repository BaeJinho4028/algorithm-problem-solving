#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> p(1005, -1);
tuple<int, int, int> edge[1000005];
int cnt;
long long ans;

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool dif(int u, int v){
	u = find(u); v = find(v);
	if (u == v) return 0;

	if (p[u] == p[v]) p[u] --;
	if (p[u] < p[v]) p[v] = u;
	else p[u] = v;
	return 1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int cost;
			cin >> cost;
			if (i >= j) continue;
			edge[m++] = { cost, i, j };
		}
	}
	sort(edge, edge + m);

	for (int i = 0; i < m; i++) {
		int a, b, cost;
		tie(cost, a, b) = edge[i];
		if (!dif(a,b)) continue;
		ans += cost;
		cnt++;
		if (cnt == n - 1) break;
	}
	cout << ans;
}