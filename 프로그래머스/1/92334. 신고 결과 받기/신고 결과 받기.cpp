#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    map<string, set<string>> ma;
    map<string, set<string>> cnt;
    
    for (string& s : report) {
        string a, b;
        stringstream ss(s);
        ss >> a >> b;
        
        ma[a].insert(b);
        cnt[b].insert(a);
    }
    
    vector<int> answer;
    for (string& s : id_list) {
        int ans = 0;
        for (auto& x : ma[s]) {
            if (cnt[x].size() >= k) ans++;
        }
        answer.push_back(ans);
    }
    
    return answer;
}