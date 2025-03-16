#include <bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator()(const pair<int, int> & a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};

// 1000 + 1000 * 500 (SJT)
int solution(vector<vector<int>> jobs) {
    // 작업 요청 시점 순 정렬
    sort(jobs.begin(), jobs.end());
    
    // 작업 소요시간 순 힙
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    
    int answer = 0;
    int cur_time = 0;
    int i = 0;
    int jobs_size = jobs.size();
    while (true) {
        // 작업을 다 처리했을 경우
        if (i >= jobs_size && pq.empty()) {
            break;
        }
        
        // 특정 작업의 요청시점이 현재시간 보다 이전일때 작업 추가
        while (i < jobs_size && jobs[i][0] <= cur_time) {
            pq.push({jobs[i][0], jobs[i][1]});
            i++;
        }
        
        // 작업 처리 후 현재시간 변경
        if (!pq.empty()) {
            answer += (cur_time - pq.top().first + pq.top().second);
            cur_time += pq.top().second;
            pq.pop();
        }
        else {
            cur_time = jobs[i][0];
        }
    }
    return answer / jobs_size;
}