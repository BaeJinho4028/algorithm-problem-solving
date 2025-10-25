#include <bits/stdc++.h>

using namespace std;

/*
다른 출입구를 방문해서는 안됨.
길 중에 최대 길이 길을 최소로 해야함.
다익스트라
*/

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<bool> chk(n + 1, false);
    for (int s : summits) {
        chk[s] = true;
    }
    
    vector<pair<int, int>> adj[n + 1];
    for (auto& p : paths) {
        adj[p[0]].push_back({p[2], p[1]});
        adj[p[1]].push_back({p[2], p[0]});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(n + 1, '????');
    for (int g : gates) {
        dist[g] = 0;
        pq.push({dist[g], g});
    }
    
    while (!pq.empty()) {
        auto [cw, cu] = pq.top();
        pq.pop();
        
        if (dist[cu] != cw) continue;
        for (auto [nw, nu] : adj[cu]) {
            if (dist[nu] > max(cw, nw)) {
                dist[nu] = max(cw, nw);
                if (!chk[nu]) {
                    pq.push({dist[nu], nu});
                } 
            }
        }
    }
    
    sort(summits.begin(), summits.end());
    
    vector<int> answer;
    int ans = 0;
    for (int s: summits) {
        if (dist[ans] > dist[s]) ans = s;
    }
    return {ans, dist[ans]};
}