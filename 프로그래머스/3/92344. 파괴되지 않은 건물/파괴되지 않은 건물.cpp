#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int n = board.size();
    int m = board[0].size();
    
    vector<vector<int>> d(n + 1, vector<int>(m + 1));
    
    for (auto& s : skill) {
        int type = s[0], val = s[5];
        int r1 = s[1], c1 = s[2], r2 = s[3], c2 = s[4];
        if (type == 1) val *= -1;
        d[r1][c1] += val;
        d[r1][c2 + 1] -= val;
        d[r2 + 1][c1] -= val;
        d[r2 + 1][c2 + 1] += val;
    }
    
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            d[i][j] += d[i - 1][j];
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            d[i][j] += d[i][j - 1];
        }
    }
    
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (d[i][j] + board[i][j] > 0) answer++;
        }
    }
    return answer;
}