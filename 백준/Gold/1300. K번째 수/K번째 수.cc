#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n, k;

ll solve(ll mid) {
	ll cnt = 0;
	for (int i = 1; i <= n; i++)
		cnt += min(mid / i, n);

	return cnt >= k;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	ll st = 0, en = n * n;

	while (st < en) {
		ll mid = (st + en) / 2;
		if (solve(mid)) en = mid;
		else st = mid + 1;
	}

	cout << st;
}