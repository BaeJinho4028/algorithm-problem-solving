#include <bits/stdc++.h>
using namespace std;

int a[4005], b[4005], c[4005], d[4005];
int ab[16000005], cd[16000005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ab[i * n + j] = a[i] + b[j];
			cd[i * n + j] = c[i] + d[j];
		}
	}
	sort(ab, ab + n * n);
	sort(cd, cd + n * n);

	long long ans = 0;
	for (int i = 0; i < n * n; i++)
		ans += upper_bound(cd, cd + n * n, -ab[i]) - lower_bound(cd, cd + n * n, -ab[i]);

	cout << ans;
}