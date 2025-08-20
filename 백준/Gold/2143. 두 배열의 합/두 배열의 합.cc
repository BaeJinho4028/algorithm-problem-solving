#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a[1005], b[1005];
ll sa[1005], sb[1005];
vector<ll> v1, v2;
ll ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sa[i] += a[i] + sa[i-1];
	}

	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		sb[i] += b[i] + sb[i - 1];
	}

	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			v1.push_back(sa[i] - sa[j]);
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < i; j++) {
			v2.push_back(sb[i] - sb[j]);
		}
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	for (int i = 0; i < v1.size(); i++) {
		int tmp = t - v1[i];
		ans += upper_bound(v2.begin(), v2.end(), tmp) - lower_bound(v2.begin(), v2.end(), tmp);
	}
	cout << ans;
}