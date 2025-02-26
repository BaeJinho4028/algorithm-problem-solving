#include <bits/stdc++.h>
using namespace std;

bool solution(string s) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    stack<char> st;
    
    for (char c : s) {
        if (c == '(') {
            st.push(c);
        } 
        else if (c == ')') {
            if (st.empty()) {
                return false;
            }
            else if (st.top() == '(') {
                st.pop();
            }
        }
    }
    return st.empty();
}