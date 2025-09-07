#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100005];
int mn = 0x7fffffff;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	int tot = a[0];

	int en = 0;
	for (int st = 0; st < n; st++) {
		while (en < n && tot < m) {
			en++;
			if (en != n) tot += a[en];
		}
		if (en == n) break;
		mn = min(mn, en - st + 1);
		tot -= a[st];
	}
	if (mn == 0x7fffffff) cout << 0;
	else cout << mn;
}
