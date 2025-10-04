#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int n = board.size();
    
    vector<stack<int>> v(n);
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] != 0) {
                v[j].push(board[i][j]);
            }
        }
    }
    
    stack<int> st;
    int answer = 0;
    for (int m : moves) {
        int idx = m - 1;
        if (v[idx].empty()) continue;
        
        int x = v[idx].top();
        v[idx].pop();
        
        if (st.empty() || st.top() != x) {
            st.push(x);
            continue;
        }
        
        answer += 2;
        st.pop();
    }
    
    return answer;
}