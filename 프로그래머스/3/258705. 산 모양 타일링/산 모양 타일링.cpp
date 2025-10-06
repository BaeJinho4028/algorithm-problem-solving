#include <bits/stdc++.h>

using namespace std;

int N;
vector<bool> T(200'003);
vector<int> d(200'003, -1);
const int MOD = 10'007;

int dfs(int cur) {
    if (cur > 2 * N + 1) return 0;
    if (cur == 2 * N + 1) return 1;
    
    int& ret = d[cur];
    if (~ret) return ret;
    
    ret = 0;
    
    ret = (ret + dfs(cur + 1)) % MOD;
    ret = (ret + dfs(cur + 2)) % MOD;
    if (T[cur]) ret = (ret + dfs(cur + 1)) % MOD;

    return ret;
}

int solution(int n, vector<int> tops) {
    N = n;
    for (int i = 0; i < n; i++) {
        if (tops[i]) {
            T[2 * (i + 1) - 1] = true;
        }
    }
    
    return dfs(0);
}