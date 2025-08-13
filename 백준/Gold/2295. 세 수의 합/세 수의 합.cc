#include <bits/stdc++.h>
using namespace std;

int a[1005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);

	vector<int> v; //두개합
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			v.push_back(a[i] + a[j]);
		}
	}
	sort(v.begin(), v.end());

	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (binary_search(v.begin(), v.end(), a[i] - a[j])) {
				cout << a[i];
				return 0;
			}
		}
	}
}