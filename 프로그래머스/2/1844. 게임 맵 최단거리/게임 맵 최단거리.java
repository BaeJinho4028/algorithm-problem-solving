import java.util.*;

class Solution {
    public int solution(int[][] maps) {
        int n = maps.length;
        int m = maps[0].length;
        
        int[][] dist = new int[n][m];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(dist[i], -1);
        }
        
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, 0});
        dist[0][0] = 1;
        
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int x = cur[0];
            int y = cur[1];
            
            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (maps[nx][ny] == 0 || dist[nx][ny] >= 0) continue;
                queue.offer(new int[]{nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
        return dist[n - 1][m - 1];
    }
}