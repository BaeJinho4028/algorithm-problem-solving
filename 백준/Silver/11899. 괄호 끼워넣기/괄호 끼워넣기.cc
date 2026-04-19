#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    stack<char> st;
    int cnt = 0;

    for (char c : s) {
        if (c == '(') {
            st.push(c);
        }
        else {
            if (st.empty()) {
                cnt++;
            }
            else {
                st.pop();
            }
        }
    }

    cout << cnt + st.size();
}
