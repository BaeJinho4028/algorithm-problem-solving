#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<bool> p(n + 1, true);
    p[0] = p[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (!p[i]) continue;
        for (int j = i * i; j <= n; j += i) {
            p[j] = false;
        }
    }

    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (p[i]) primes.push_back(i);
    }

    int st = 0, en = 0, sum = 0, ans = 0;
    while (true) {
        if (sum == n) ans++;

        if (sum >= n) sum -= primes[st++];
        else {
            if (en == primes.size()) break;
            sum += primes[en++];
        }
    }

    cout << ans;
}
