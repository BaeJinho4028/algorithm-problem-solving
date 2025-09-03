#include <bits/stdc++.h>
using namespace std;

int a[10005];
int n, m;

bool solve(int x) {
	int cur = 0;
	for (int i = 0; i < n; i++) cur += min(a[i], x);
	return m >= cur;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);

	cin >> m;

	int st = 0, en = a[n-1];
	while (st < en) {
		int mid = (st + en +1)/2;
		if (solve(mid)) st = mid;
		else en = mid - 1;
	}

	cout << st;
}