#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<string>> v;
int ans;
set<set<string>> chk;

void f(int cur, set<string>& se) {
    if (cur == n) {
        if (se.size() == n && !chk.count(se)) {
            chk.insert(se);
            ans++;
        }
        return;
    }
    
    for (int i = 0; i < v[cur].size(); ++i) {
        set<string> tmp = se;
        tmp.insert(v[cur][i]);
        f(cur + 1, tmp);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    n = banned_id.size();
    v.resize(n);
    
    for (int i = 0; i < n; ++i) {
        string b = banned_id[i];
        
        for (string u : user_id) {
            if (b.size() != u.size()) continue;
            
            bool flag = true;
            for (int j = 0; j < b.size(); ++j) {
                if (b[j] != '*' && b[j] != u[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) v[i].push_back(u);
        }
    }
    
    set<string> se;
    f(0, se);
    
    return ans;
}