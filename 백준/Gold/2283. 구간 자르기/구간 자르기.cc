#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    
    vector<int> v(1'000'001);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;

        for (int j = a; j < b; ++j) {
            v[j]++;
        }
    }

    int st = 0, en = 0;
    int sum = 0;
    const int MAX = 1'000'000;
    while (st < MAX) {
        while (sum < k && en <= MAX) {
            sum += v[en++];
        }
        if (sum == k) {
            cout << st << ' ' << en;
            return 0;
        }
        sum -= v[st++];
    }
    cout << "0 0";
}
