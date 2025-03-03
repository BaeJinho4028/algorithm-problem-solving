#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size);
    
    stack<int> st;
    for (int i = 0; i < size; i++) {
        while (!st.empty() && prices[st.top()] > prices[i]) {
            answer[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    
    while (!st.empty()) {
        answer[st.top()] = size - st.top() - 1;
        st.pop();
    }
    return answer;
}