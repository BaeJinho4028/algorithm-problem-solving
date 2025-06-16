#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));
    
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int x = 0, y = 0, dir = 0;
    
    for (int i = 1; i <= n * n; ++i) {
        answer[x][y] = i;
        
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || answer[nx][ny] != 0) {
            dir = (dir + 1) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }
        
        x = nx;
        y = ny;
    }
    
    return answer;
}