#include <bits/stdc++.h>

using namespace std;

vector<int> answer = {-1};
int mx = 0;

void dfs(int cur, int n, int idx, vector<int>& info, vector<int>& ryan) {
    if (cur == n) {
        int tmp = 0;
        for (int i = 0; i < 11; ++i) {
            if (ryan[i] > info[i]) tmp += (10 - i);
            else if (info[i]) tmp -= (10 - i);
        }
        
        if (mx < tmp) {
            mx = tmp;
            answer = ryan;
        }
        else if (tmp && mx == tmp) {
            for (int i = 10; i >= 0; --i) {
                if (answer[i] > ryan[i]) return;
                else if (answer[i] < ryan[i]) {
                    answer = ryan;
                    break;
                }
            }
        }
        return;
    }
    
    for (int i = idx; i <= 10; ++i) {
        int num = info[i] + 1;
        if (num > n - cur) num = n - cur;
        ryan[i] = num;
        dfs(cur + num, n, i + 1, info, ryan);
        ryan[i] = 0;
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> ryan(11, 0);
    dfs(0, n, 0, info, ryan);
    return answer;
}