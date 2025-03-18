#include <bits/stdc++.h>
using namespace std;

int ans = INT_MAX;

void dfs(int n, int number, int cnt, int cur) {
    if (cnt > 8) return;
    if (cur == number) {
        ans = min(ans, cnt);
        return;
    }
    
    int tmp = 0;
    for (int i = 0; i < 8 - cnt; ++i) {
        tmp = tmp * 10 + n;
        
        dfs(n, number, cnt + i + 1, cur + tmp);
        dfs(n, number, cnt + i + 1, cur - tmp);
        dfs(n, number, cnt + i + 1, cur * tmp);
        if (tmp) dfs(n, number, cnt + i + 1, cur / tmp);
    }
}

int solution(int N, int number) {    
    dfs(N, number, 0, 0);
    return ans == INT_MAX ? -1 : ans;
}
