#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, d;
    cin >> m >> d;

    static const int md[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int sum = 0;
    for (int i = 0; i < m - 1; ++i) {
        sum += md[i];
    }
    sum += (d - 1);

    static const string w[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    cout << w[sum % 7];
    return 0;
}
