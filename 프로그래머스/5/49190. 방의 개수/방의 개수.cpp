#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> arrows) {
    int answer = 0;
    
    map<int, map<int, bool>> vis_pos;
    map<int, map<int, map<int, map<int, bool>>>> vis_edge;
    vis_pos[0][0] = true;
    
    int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
    
    int x = 0;
    int y = 0;
    
    for (int a : arrows) {
        for (int i = 0; i < 2; ++i) {
            int nx = x + dx[a];
            int ny = y + dy[a];
            
            if (!vis_edge[x][y][nx][ny] && ! vis_edge[nx][ny][x][y]) {
                if (vis_pos[nx][ny]) {
                    answer++;
                }
            }
            
            vis_pos[nx][ny] = true;
            vis_edge[x][y][nx][ny] = true;
            
            x = nx;
            y = ny;
        }
    }
    
    return answer;
}