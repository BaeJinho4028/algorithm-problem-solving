#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int s1 = 0, e1 = queue1.size() - 1;
    int s2 = queue1.size(), e2 = queue1.size() * 2 - 1;
    
    
    vector<int> v;
    v.insert(v.end(), queue1.begin(), queue1.end());
    v.insert(v.end(), queue2.begin(), queue2.end());
    
    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0LL);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0LL);
    
    int len = v.size();
    
    int answer = 0;
    while (answer < len * 2) {
        if (sum1 < sum2) {
            sum1 += v[(++e1) % len];
            sum2 -= v[(s2++) % len];
        }
        else if (sum1 > sum2) {
            sum1 -= v[(s1++) % len];
            sum2 += v[(++e2) % len];
        }
        else return answer;
        answer++;
    }
    return -1;
    
    return answer;
}