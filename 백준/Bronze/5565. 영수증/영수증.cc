#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum;
    cin >> sum;

    for (int i = 0; i < 9; ++i) {
        int x;
        cin >> x;
        sum -= x;
    }

    cout << sum;
}
