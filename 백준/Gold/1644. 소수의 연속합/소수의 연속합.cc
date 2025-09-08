#include <bits/stdc++.h>
using namespace std;

const int MX = 4000002;
vector<bool> pn(MX, true);
vector<int> primes;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 2; i*i < MX; i++) {
		if (!pn[i]) continue;
		for (int j = i * i; j < MX; j += i)
			pn[j] = false;
	}
	for (int i = 2; i < MX; i++) if (pn[i]) primes.push_back(i);
	primes.push_back(0);

	int target, st = 0, en = 1, ans = 0, tmp = primes[0];
	cin >> target;

	while (1) {
		if (tmp == target) ans++;
		if (tmp <= target) tmp += primes[en++];
		if (tmp > target) tmp -= primes[st++];
		if (en == int(primes.size())) break;
	}
	cout << ans;
}