#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> clothes) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    map<string, int> ma;
    for(auto c : clothes) {
        ma[c[1]]++;
    }
    
    int answer = 1;
    for(auto c : ma) {
        answer *= (c.second + 1);
    }
    return answer - 1;
}