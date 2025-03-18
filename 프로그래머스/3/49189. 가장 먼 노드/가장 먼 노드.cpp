#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> edge) {    
    vector<vector<int>> graph(n + 1);
    vector<int> dist(n + 1, -1);
    
    for (auto& e : edge) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt : graph[cur]) {
            if (dist[nxt] == -1) {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }
    
    int mx = *max_element(dist.begin(), dist.end());
    
    int answer = 0;
    for (int i = 2; i <= n; i++) {
        if (dist[i] == mx) {
            answer++;
        }
    }
    
    return answer;
}