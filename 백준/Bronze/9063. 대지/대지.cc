#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    int mn_x = '????', mn_y = '????', mx_x = -'????', mx_y = -'????';

    while (n--) {
        int x, y;
        cin >> x >> y;
        mn_x = min(mn_x, x);
        mn_y = min(mn_y, y);
        mx_x = max(mx_x, x);
        mx_y = max(mx_y, y);
    }

    cout << (mx_x - mn_x) * (mx_y - mn_y);
}
