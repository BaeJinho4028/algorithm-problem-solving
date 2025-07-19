#include <bits/stdc++.h>
using namespace std;

int n, m;
long long state[10];

int bit_cnt(long long x) {
    int ret = 0;
    for (int i = 0; i < max(n, m); ++i) {
        ret += (x >> i) & 1;
    }
    return ret;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        string a, b;
        cin >> a >> b;
        for (int j = m - 1; j >= 0; --j) {
            state[i] = (state[i] << 1) | (b[j] == 'Y');
        }
    }

    pair<int, int> ans = {0, -1};
    for (int i = 0; i < (1 << n); ++i) {
        long long comb = 0;
        for (int j = 0; j < n; ++j) {
            if ((i & (1LL << j)) == 0) continue;
            comb |= state[j];
        }

        int song = bit_cnt(comb);
        int guitar = bit_cnt(i);

        if (ans.first < song) {
            ans = {song, guitar};
        }
        else if (ans.first == song && ans.second > guitar) {
            ans = {song, guitar};
        }
    }
    cout << ans.second;
}
