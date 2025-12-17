#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    long long sum = 0;
    int x = 0, y = 0;
    vector<int> px(n), py(n);
    for (int i = 0; i < n; ++i) {
        cin >> px[i] >> py[i];
        sum += abs(px[i]) + abs(py[i]);
    }
    sort(px.begin(), px.end());
    sort(py.begin(), py.end());

    string s;
    cin >> s;
    for (char c : s) {
        if (c == 'S') {
            int pos = upper_bound(py.begin(), py.end(), y) - py.begin();
            sum += (pos - (n - pos));
            y++;
        }
        else if (c == 'J') {
            int pos = lower_bound(py.begin(), py.end(), y) - py.begin();
            sum -= (pos - (n - pos));
            y--;
        }
        else if (c == 'I') {
            int pos = upper_bound(px.begin(), px.end(), x) - px.begin();
            sum += (pos - (n - pos));
            x++;
        }
        else if (c == 'Z') {
            int pos = lower_bound(px.begin(), px.end(), x) - px.begin();
            sum -= (pos - (n - pos));
            x--;
        }

        cout << sum << '\n';
    }
}
