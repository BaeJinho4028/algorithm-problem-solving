#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> priorities, int location) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    queue<pair<int,int>> q;
    priority_queue<int> pq;
    for (int i = 0; i < priorities.size(); ++i) {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    
    int ans = 0;
    while (true) {
        if (q.front().first == pq.top()) {
            ++ans;
            pq.pop();
            if(q.front().second == location) {
                break;
            }
        }
        else {
            q.push(q.front());
        }
        q.pop();
    }
    return ans;
}