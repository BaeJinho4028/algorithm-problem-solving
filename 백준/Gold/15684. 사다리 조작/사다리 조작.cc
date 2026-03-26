#include <bits/stdc++.h>
using namespace std;

int n, m, h;
bool vis[35][15];

void dfs(int ch, int cur, int ans) {
    if (cur == ans) {
        bool flag = true;

        for (int st = 1; st <= n; ++st) {
            int cx = st;

            for (int j = 1; j <= h; ++j) {
                if (vis[j][cx]) cx++;
                else if (vis[j][cx - 1]) cx--;
            }

            if (cx != st) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << ans;
            exit(0);
        }
        return;
    }

    for (int i = ch; i <= h; ++i) {
        for (int j = 1; j < n; ++j) {
            if (vis[i][j - 1] || vis[i][j] || vis[i][j + 1]) continue;
            vis[i][j] = true;
            dfs(i, cur + 1, ans);
            vis[i][j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> h;

    while (m--) {
        int a, b;
        cin >> a >> b;
        vis[a][b] = true;
    }

    for (int ans = 0; ans <= 3; ++ans) {
        dfs(1, 0, ans);
    }

    cout << -1;
}
