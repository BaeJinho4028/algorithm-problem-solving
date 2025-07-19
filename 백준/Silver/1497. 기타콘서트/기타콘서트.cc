#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> state(n, 0);
    long long possible = 0;

    for (int i = 0; i < n; ++i) {
        string _, s;
        cin >> _ >> s;
        
        for (int j = 0; j < m; ++j) {
            if (s[j] == 'Y') {
                state[i] |= (1LL << j);
                possible |= (1LL << j);
            }
        }
    }

    if (possible == 0) {
        cout << -1;
        return 0;
    }

    int mn = '????';
    for (int i = 1; i <= (1 << n); ++i) {
        int cnt = 0;
        long long chk = 0;

        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                cnt++;
                chk |= state[j];
            }
        }

        if (chk == possible) {
            mn = min(mn, cnt);
        }
    }

    cout << mn;
}
