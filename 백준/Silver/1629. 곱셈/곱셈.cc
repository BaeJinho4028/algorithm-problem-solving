#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mul(int a, int b, int c) {
	if (b == 1) return a % c;
	ll half = mul(a, b / 2, c);
	half = half * half % c;
	if (b % 2 == 1) return half * a % c;
	else return half % c;

}

int main() {
	ll a, b, c;
	cin >> a >> b >> c;

	cout << mul(a, b, c);
}