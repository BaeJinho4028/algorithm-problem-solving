#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  
  set<string> se;
  string s;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    se.insert(s);
  }

  int ans = 0;
  for (int i = 0; i < m; ++i) {
    cin >> s;
    if (se.find(s) != se.end()) {
      ans++;
    }
  }
  cout << ans;
  
  return 0;
}
