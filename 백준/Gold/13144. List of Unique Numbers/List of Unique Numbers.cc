#include <bits/stdc++.h>
using namespace std;

int a[100005];
int mn = 0x7fffffff;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	vector<bool> chk(100005);
	for (int i = 0; i < n; i++) cin >> a[i];

	long long ans = 0;
	chk[a[0]] = 1;
	int en = 0;
	for (int st = 0; st < n; st++) {
		while (en < n-1 && !chk[a[en+1]]) {
			en++;
			chk[a[en]] = 1;
		}
		ans += (en - st + 1);
		chk[a[st]] = 0;
	}

	cout << ans;
}