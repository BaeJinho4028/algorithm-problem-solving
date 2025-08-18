#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int m, n;
int a[100005];
int ans = 1e9 + 1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	int st = 0, en = n - 1;
	while (st < en) {
		int val = a[st] + a[en];
		if (abs(val) < abs(ans)) ans = val;
		if (val < 0)st++;
		else en--;
	}

	cout << ans;
}