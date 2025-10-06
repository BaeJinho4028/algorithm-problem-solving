#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {    
    map<string, map<string, int>> gt;
    map<string, int> p, ans;
    
    for (string g : gifts) {
        string a, b;
        stringstream ss(g);
        ss >> a >> b;
        gt[a][b]++;
    }
    
    for (string a : friends) {
        p[a] = 0;
        ans[a] = 0;
        
        int give = 0, take = 0;
        for (string b : friends) {
            if (a == b) continue;
            give += gt[a][b];
            take += gt[b][a];
        }
        p[a] = give - take;
    }
    
    for (int i = 0; i < friends.size(); i++) {
        for (int j = i + 1; j < friends.size(); j++) {
            string a = friends[i];
            string b = friends[j];
            
            if (gt[a][b] > gt[b][a]) ans[a]++;
            else if (gt[a][b] < gt[b][a]) ans[b]++;
            else {
                if (p[a] > p[b]) ans[a]++;
                else if (p[a] < p[b]) ans[b]++;
            }
        }
    }
    
    int answer = 0;
    for (string f : friends) {
        answer = max(answer, ans[f]);
    }
    
    return answer;
}