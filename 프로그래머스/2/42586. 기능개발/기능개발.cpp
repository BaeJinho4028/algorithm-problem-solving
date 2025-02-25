#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<pair<int, int>> q;
    for (int i = 0; i< progresses.size(); i++){
        q.push({progresses[i], speeds[i]});
    }
    
    for (int day = 1; day <= 100 && !q.empty(); ++day){
        int cnt = 0;
        
        while (q.front().first + q.front().second * day >= 100){
            q.pop();
            cnt++;
        }
        
        if(cnt) {
            answer.push_back(cnt);
        }
    }
    
    return answer;
}