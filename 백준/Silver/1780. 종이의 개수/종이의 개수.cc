#include <bits/stdc++.h>
using namespace std;

int board[2200][2200];
int ans[3];

void f(int n, int x, int y) {
    int k = board[x][y];
    if (n == 0) {
        ans[k + 1]++;
    }

    bool flag = true;
    for (int i = x; i < x + n; ++i) {
        for (int j = y; j < y + n; ++j) {
            if (k != board[i][j]) flag = false;
        }
    }
    
    if (flag) {
        ans[k + 1]++;
    }
    else {
        int tmp = n / 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                f(tmp, x + i * tmp, y + j * tmp);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    f(n, 0, 0);

    for (int i = 0; i < 3; i++) {
		cout << ans[i] << '\n';
	}

    return 0;
}
