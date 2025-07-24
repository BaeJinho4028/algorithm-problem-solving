#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, cnt;
long long ans;
vector<pair<int, int>> adj[100005];
bool chk[100005];
priority_queue< tuple<int, int, int>,
	vector<tuple<int, int, int>>,
	greater<tuple<int, int, int>> > pq;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int w;
		cin >> w;
		adj[0].push_back({ w, i }); // 0 이라는 노드추가
		adj[i].push_back({ w, 0 });
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int cost;
			cin >> cost;
			adj[i].push_back({ cost, j });
		}
	}

	chk[1] = 1;
	for (auto nxt : adj[1])
		pq.push({ nxt.X, 1, nxt.Y }); // 비용, 정점1, 정점2

	while (cnt < n) { // 노드 하나를 추가해서 (n-1)+1
		int a, b, cost;
		tie(cost, a, b) = pq.top(); pq.pop();
		if (chk[b]) continue;
		ans += cost;
		chk[b] = 1;
		cnt++;
		for (auto nxt : adj[b]) {
			if (!chk[nxt.Y])
				pq.push({ nxt.X, b, nxt.Y });
		}
	}
	cout << ans;
}