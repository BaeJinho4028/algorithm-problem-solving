#include <bits/stdc++.h>
using namespace std;

/*
1초가 지나며 다리(큐)에서 빠짐, 다리로 차가 들어감.
빠질 때는 다리를 건넜는지 체크 (시간으로!)
들어갈 때는 다리 길이와 무게 체크
다 빠지는 순간 끝.
*/

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    int cnt = 0;
    int w = 0;
    int t_sum = truck_weights.size();
    queue<pair<int,int>> q; // 트럭무게, 지나는 시간
    while (true) {   
        ++time;
                
        if (!q.empty() && q.front().second <= time) {
            w -= q.front().first;
            q.pop();
        }  
        
        if(q.size() < bridge_length && cnt < t_sum && w + truck_weights[cnt] <= weight) {
            q.push({truck_weights[cnt], time + bridge_length});
            w += truck_weights[cnt++];
        }    
        
        if (cnt == t_sum && q.empty()) {
            break;
        }
    }
    
    return time;
}