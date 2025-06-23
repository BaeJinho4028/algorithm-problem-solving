class Solution {
    public int[][] solution(int[] num_list, int n) {
        int len = num_list.length;
        int r = len / n;
        int[][] answer = new int[r][n];
        
        for (int i = 0; i < len; i++) {
            answer[i / n][i % n] = num_list[i];
        }
        
        return answer;
    }
}