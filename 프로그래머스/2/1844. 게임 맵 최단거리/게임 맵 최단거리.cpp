#include<bits/stdc++.h>
using namespace std;

int solution(vector<vector<int> > maps)
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int,int>> q;
    
    q.push({0, 0});
    int dx[] = {1, 0 , -1, 0};
    int dy[] = {0, 1, 0, -1};
    dist[0][0] = 1;
    
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;
        
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (maps[nx][ny] == 0 || dist[nx][ny] >= 0) continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }
    return dist[n - 1][m - 1];
}