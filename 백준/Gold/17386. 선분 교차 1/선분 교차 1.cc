#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
};

ll ccw(Point a, Point b, Point c) {
    ll tmp = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (tmp > 0) return 1;
    if (tmp < 0) return -1;
    else 0;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    Point a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y;
    cin >> c.x >> c.y >> d.x >> d.y;

    ll ab_c = ccw(a, b, c);
    ll ab_d = ccw(a, b, d);
    ll cd_a = ccw(c, d, a);
    ll cd_b = ccw(c, d, b);

    if (ab_c * ab_d < 0 && cd_a * cd_b < 0) {
        cout << 1;
    }
    else {
        cout << 0;
    }
}

