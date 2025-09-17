#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[9];
int vis[9];

void bt(int cur) {
    if (cur == m) {
        for (int i = 0; i < m; ++i) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        vis[i] = true;
        a[cur] = i;
        bt(cur + 1);
        vis[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    bt(0);
}
