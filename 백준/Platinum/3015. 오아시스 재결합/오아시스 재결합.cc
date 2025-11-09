#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	
	stack<pair<int,int>> st;

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int h;
		cin >> h;

		while (!st.empty() && h > st.top().first) {
			ans += st.top().second;
			st.pop();
		}

		if (st.empty()) {
			st.push({ h, 1 });
		}

		else if (st.top().first == h) {
			int cur = st.top().second;
			st.pop();
			if (!st.empty())ans++;
			
			ans += cur;
			st.push({ h, cur + 1 });
		}

		else {
			ans++;
			st.push({ h, 1 });
		}
	}
	cout << ans;
}