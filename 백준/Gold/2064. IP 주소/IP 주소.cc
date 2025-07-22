#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> p(10'005, -1);

int to_int(string& ip) {
    int a, b, c, d;
    sscanf(ip.c_str(), "%d.%d.%d.%d", &a, &b, &c, &d);
    return (a << 24) | (b << 16) | (c << 8) | d;
}

string to_ip(int ip) {
    return to_string((ip >> 24) & 255) + '.' +
        to_string((ip >> 16) & 255) + '.' +
        to_string((ip >> 8) & 255) + '.' +
        to_string(ip & 255);
}

int main() {
    int n;
    cin >> n;
    vector<int> ips(n);
    for (int i = 0; i < n; ++i) {
        string ip;
        cin >> ip;
        ips[i] = to_int(ip);
    }

    int mn = *min_element(ips.begin(), ips.end());
    int mx = *max_element(ips.begin(), ips.end());

    int chk = mn ^ mx;
    int prefix = 0;
    for (int i = 31; i >= 0; --i) {
        if ((chk >> i) & 1) break;
        prefix++;
    }

    int mask = (prefix == 0) ? 0 : (~0 << (32 - prefix));
    int net = mn & mask;

    cout << to_ip(net) << '\n' << to_ip(mask);
}
