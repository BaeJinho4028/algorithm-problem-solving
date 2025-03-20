#include <bits/stdc++.h>
using namespace std;

int dfs(int cur, int parent, int cnt, vector<vector<int>> &e) {
    for (int nxt : e[cur]) {
        if (nxt != parent) {
            cnt = dfs(nxt, cur, cnt + 1, e);
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;
    vector<vector<int>> e(n + 1);
    for (auto w : wires) {
        e[w[0]].push_back(w[1]);
        e[w[1]].push_back(w[0]);
    }
    
    for (auto w : wires) {
        int sum = dfs(w[0], w[1], 1, e);
        int cmp = abs(n - (2 * sum));
        answer = min(answer, cmp);
    }
    
    return answer;
}