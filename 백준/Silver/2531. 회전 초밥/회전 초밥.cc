#include <bits/stdc++.h>
using namespace std;

int n, d, k, c;
int a[30005]; 
bool chk[30005];
int cnt = 0;

int main() {
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) 
		cin >> a[i];

	for (int i = 0; i < n; i++) {
		int flag = 0;
		for (int j = i; j < i + k; j++) {
			if (chk[a[j % n]]) flag++;
			chk[a[j % n]] = true;
		}
		cnt = max(cnt, k - flag + !chk[c]);
		memset(chk, false, sizeof(chk));
	}
	cout << cnt << endl;
}