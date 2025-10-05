#include <bits/stdc++.h>

using namespace std;

// 못건너면 en 을 다운

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int st = *min_element(stones.begin(), stones.end());
    int en = *max_element(stones.begin(), stones.end());
    
    while (st <= en) {
        int mid = (st + en) / 2;
        
        int cnt = 0;
        int tmp = 0;
        for (int s : stones) {
            if (s > mid) {
                tmp = 0;
            }
            else {
                tmp++;
                cnt = max(cnt, tmp);
            }
        }
        
        if (cnt >= k) en = mid - 1;
        else st = mid + 1;
    }
    
    return st;
}

// k만큼 벌어지는 최소 시간 2억 2000000만 킹분 갓색