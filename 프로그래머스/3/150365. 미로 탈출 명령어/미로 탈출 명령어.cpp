#include <bits/stdc++.h>

using namespace std;

int N, M, X, Y, R, C, K;
bool flag = false;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char dc[4] = {'d', 'l', 'r', 'u'};

string tmp = "";
string answer = "impossible";

int get_dist(int x, int y) {
    return abs(R - x) + abs(C - y);
}

void dfs(int cnt, int cx, int cy) {
    if (flag) return;
    
    int dist = get_dist(cx, cy);
    if (K - cnt - dist < 0) return;
    if ((K - cnt - dist) % 2 == 1) return;
    
    if (cnt == K) {
        if (cx == R && cy == C) {
            flag = true;
            answer = tmp;
        }
        return;
    }
    
    for (int dir = 0; dir < 4; ++dir) {
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];
        if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
        tmp += dc[dir];
        dfs(cnt + 1, nx, ny);
        tmp.pop_back();
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {    
    N = n, M = m, X = x, Y = y, R = r, C = c, K = k;
    dfs(0, x, y);
    
    return answer;
}