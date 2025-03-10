#include <bits/stdc++.h>
using namespace std;

void dfs(int idx, int n, const vector<vector<int>>& computers, vector<bool>& visited) {
    visited[idx] = true;
    for (int i = 0; i < n; ++i) {
        if (computers[idx][i] && !visited[i]) {
            dfs(i, n, computers, visited);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    vector<bool> visited(n, false);
    int answer = 0;
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, n, computers, visited);
            answer++;
        }
    }
    return answer;
}

/*


vector<int> adj[205];
bool vis[205];
int cnt;

void dfs(int x){
    vis[x] = true;
    for(int nxt : adj[x]){
        if(vis[nxt]) continue;
        dfs(nxt);
    }
}

int solution(int n, vector<vector<int>> computers) {
    
    for(int i=0; i<computers.size(); i++){
        for(int j=0; j<computers[i].size(); j++){
            if(computers[i][j]) adj[i].push_back(j);
        }
    }
    
    for(int i = 0; i<n; i++){
        if(vis[i]) continue;
        dfs(i);
        cnt++;
    }
    
    int answer = cnt;
    return answer;
}
*/