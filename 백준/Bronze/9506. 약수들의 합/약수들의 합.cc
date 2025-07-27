#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while (cin >> n) {
        if (n == -1) return 0;

        vector<int> v;
        int sum = 0;
        for (int i = 2; i < n; ++i) {
            if (n % i == 0) {
                sum += i;
                v.push_back(i);
            }
        }
        if (sum + 1 == n) {
            cout << n << " = 1";
            for (int x : v) {
                cout << " + " << x;
            }
        }
        else {
            cout << n << " is NOT perfect.";
        }
        cout << '\n';
    }
}
