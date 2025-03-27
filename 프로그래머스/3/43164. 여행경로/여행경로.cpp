#include <bits/stdc++.h>
using namespace std;

bool dfs(string cur, int cnt, vector<vector<string>>& t, vector<bool>& vis, vector<string>& answer) {
    answer.push_back(cur);
    if (cnt == t.size()) return true;
    
    for (int i = 0; i < t.size(); ++i) {
        if (vis[i]) continue;
        if (t[i][0] != cur) continue;
        
        vis[i] = true;
        if (dfs(t[i][1], cnt + 1, t, vis, answer)) return true;
        vis[i] = false;
    }
    
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> vis(tickets.size());
    sort(tickets.begin(), tickets.end());
    
    dfs("ICN", 0, tickets, vis, answer);
    
    return answer;
}