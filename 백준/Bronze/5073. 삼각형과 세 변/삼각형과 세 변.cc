#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t[3];
    while (cin >> t[0] >> t[1] >> t[2]) {
        if (t[0] == 0 && t[1] == 0 && t[2] == 0) break;
        sort(begin(t), end(t));

        if (t[0] + t[1] <= t[2]) {
            cout << "Invalid\n";
        }
        else if (t[0] == t[2]) {
            cout << "Equilateral\n";
        }
        else if (t[0] == t[1] || t[1] == t[2]) {
            cout << "Isosceles\n";
        } else {
            cout << "Scalene\n";
        }
    }
}
