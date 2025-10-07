#include <bits/stdc++.h>

using namespace std;

int f(string& s) {
    
    vector<int> v;
    string tmp = "";
    for (char c : s) {
        if (c == '.') {
            v.push_back(stoi(tmp));
            tmp.clear();
            continue;
        }
        tmp += c;
    }
    v.push_back(stoi(tmp));

    return v[0] * 12 * 28 + v[1] * 28 + v[2];
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    map<string, int> ma;
    for (string t : terms) {
        stringstream ss(t);
        string a;
        int b;
        ss >> a >> b;
        ma[a] = 28 * b;
    }
    
    int tod = f(today);
    
    for (int i = 0; i < privacies.size(); ++i) {
        string p = privacies[i];
        stringstream ss(p);
        string a, b;
        ss >> a >> b;
        
        if (tod > f(a) + ma[b] - 1) answer.push_back(i + 1);
    }
    
    return answer;
}