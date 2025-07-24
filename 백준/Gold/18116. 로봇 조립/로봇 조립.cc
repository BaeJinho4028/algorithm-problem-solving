#include <bits/stdc++.h>
using namespace std;

vector<int> p(1'000'000, -1);
vector<int> robot(1'000'000, 1);

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return true;
    p[u] = v;
    robot[v] += robot[u];
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        char c;
        cin >> c;
        
        if (c == 'I') {
            int a, b;
            cin >> a >> b;
            uni(a, b);
        } 
        else {
            int x;
            cin >> x;
            cout << robot[find(x)] << '\n';
        }
    }
}
