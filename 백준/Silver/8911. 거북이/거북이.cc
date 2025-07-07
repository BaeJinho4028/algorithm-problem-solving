#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int x = 0;
        int y = 0;

        int mn_x = 0, mx_x = 0;
        int mn_y = 0, mx_y = 0;

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        int dir = 0;

        string s;
        cin >> s;

        for (char c : s) {
            if (c == 'F') {
                x += dx[dir];
                y += dy[dir];
                mn_x = min(mn_x, x);
                mx_x = max(mx_x, x);
                mn_y = min(mn_y, y);
                mx_y = max(mx_y, y);
            } else if (c == 'B') {
                x -= dx[dir];
                y -= dy[dir];
                mn_x = min(mn_x, x);
                mx_x = max(mx_x, x);
                mn_y = min(mn_y, y);
                mx_y = max(mx_y, y);
            } else if (c == 'L') {
                dir = (dir + 3) % 4;
            } else if (c == 'R') {
                dir = (dir + 1) % 4;
            }
        }
        cout << abs((mx_x - mn_x) * (mx_y - mn_y)) << '\n';
    }
}
