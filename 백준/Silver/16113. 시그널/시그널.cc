#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<string, int> ma = {
        {"####.##.##.####", 0}, 
        {"###..#####..###", 2}, 
        {"###..####..####", 3}, 
        {"#.##.####..#..#", 4}, 
        {"####..###..####", 5}, 
        {"####..####.####", 6}, 
        {"###..#..#..#..#", 7}, 
        {"####.#####.####", 8}, 
        {"####.####..####", 9}
    };

    int n;
    cin >> n;

    n /= 5;

    string s;
    cin >> s;

    vector<string> v;
    for (int i = 0; i < s.size(); i += n) {
        v.push_back(s.substr(i, n));
    }

    for (int i = 0; i < n; ++i) {
        if (v[0][i] == '#') {
            if (i == n - 1 || (v[0][i + 1] == '.' && v[3][i] == '#')) {
                cout << 1;
                continue;
            }

            string num = "";
            for (int j = 0; j < 5; ++j) {
                num += v[j].substr(i, 3);
            }

            if (ma.find(num) != ma.end()) {
                cout << ma[num];
                i += 3;
            }
        }
    }
}
