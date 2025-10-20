#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int tc = 1;; tc++) {
        int n;
        cin >> n;
        if (!n) return 0;

        vector<vector<int>> tri(n + 1, vector<int>(2 * n + 2, 0));
        vector<vector<int>> sum(n + 1, vector<int>(2 * n + 2, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < 2 * i; j++) {
                cin >> tri[i][j];
                sum[i][j] = sum[i][j - 1] + tri[i][j];
            }
        }

        int ans = -'????';

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < 2 * i; j += 2) {
                int cur = 0;
                for (int k = 0; k <= n - i; k++) {
                    cur += sum[i + k][j + 2 * k] - sum[i + k][j - 1];
                    ans = max(ans, cur);
                }
            }
        }

        for (int i = n; i >= 1; i--) {
            for (int j = 2; j < 2 * i; j += 2) {
                int cur = 0;
                for (int k = 0; k <= n; k++) {
                    if (j - 2 * k - 1 < 0 || j >= 2 * (i - k)) break;
                    cur += sum[i - k][j] - sum[i - k][j - 2 * k - 1];
                    ans = max(ans, cur);
                }
            }
        }

        cout << tc << ". " << ans << '\n';
    }
}
