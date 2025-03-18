#include <bits/stdc++.h>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    unordered_set<string> se(words.begin(), words.end());
    
    queue<pair<string, int>> q;
    unordered_set<string> vis;
    
    q.push({begin, 0});
    vis.insert(begin);
    
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        
        if (cur.first == target) {
            return cur.second;
        }
        
        for (int i = 0; i < cur.first.size(); ++i) {
            string nxt = cur.first;
            for (char c = 'a'; c <= 'z'; c++) {
                if(nxt[i] == c) continue;
                nxt[i] = c;
                if (se.count(nxt) && !vis.count(nxt)) {
                    q.push({nxt, cur.second + 1});
                    vis.insert(nxt);
                }
            }
        }
    }
    return 0;
}