#include <bits/stdc++.h>
using namespace std;

int a[1005];
int d[1005];
int pre[1005];


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
				pre[i] = j;
			}
		}
	}

	int mxd = d[1];
	int mxi = 1;

	for (int i = 2; i <= n; i++) {
		if (mxd < d[i]) {
			mxd = d[i];
			mxi = i;
		}
	}

	deque<int> ans;
	int cur = mxi;
	while (cur) {
		ans.push_front(a[cur]);
		cur = pre[cur];
	}
	cout << ans.size() << '\n';
	for (auto x : ans) cout << x << ' ';
}