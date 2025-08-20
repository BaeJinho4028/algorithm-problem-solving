#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<string, int> value = {
        {"black", 0}, {"brown", 1}, {"red", 2}, {"orange", 3},
        {"yellow", 4}, {"green", 5}, {"blue", 6}, {"violet", 7},
        {"grey", 8}, {"white", 9}
    };

    map<string, long long> mul = {
        {"black", 1LL}, {"brown", 10LL}, {"red", 100LL}, {"orange", 1000LL},
        {"yellow", 10000LL}, {"green", 100000LL}, {"blue", 1000000LL}, {"violet", 10000000LL},
        {"grey", 100000000LL}, {"white", 1000000000LL}
    };

    string c1, c2, c3;
    cin >> c1 >> c2 >> c3;

    long long base = value[c1] * 10LL + value[c2];
    cout << base * mul[c3] << "\n";
}
