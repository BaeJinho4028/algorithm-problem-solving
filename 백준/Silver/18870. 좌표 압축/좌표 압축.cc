#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n), uni(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        uni[i] = v[i];
    }
    sort(uni.begin(), uni.end());
    uni.erase(unique(uni.begin(), uni.end()), uni.end());
    
    for (int i = 0; i < n; ++i) {
        cout << lower_bound(uni.begin(), uni.end(), v[i]) - uni.begin() << ' ';
    }
}
