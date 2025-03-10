class Solution {
    private void dfs(int idx, int n, int[][] computers, boolean[] visited) {
        visited[idx] = true;
        for (int i = 0; i < n; ++i) {
            if (computers[idx][i] == 1 && !visited[i]) {
                dfs(i, n, computers, visited);
            }
        }
    }
    
    public int solution(int n, int[][] computers) {
        boolean[] visited = new boolean[n];
        int answer = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, n, computers, visited);
                answer++;
            }
        }
        
        return answer;
    }
}