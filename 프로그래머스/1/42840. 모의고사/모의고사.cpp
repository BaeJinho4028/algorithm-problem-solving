#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<vector<int>> p = {
        {1, 2, 3, 4, 5}, 
        {2, 1, 2, 3, 2, 4, 2, 5}, 
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };
    
    vector<int> cnt = {0, 0, 0};
    
    for (int i = 0; i < answers.size(); ++i) {
        for (int j = 0; j < 3; ++j) {
            if (answers[i] == p[j][i % p[j].size()]) {
                cnt[j]++;
            }
        }
    }
    
    int mx = *max_element(cnt.begin(), cnt.end());
    
    for (int i = 0; i < 3; ++i) {
        if (cnt[i] == mx) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}