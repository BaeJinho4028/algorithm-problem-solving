import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        
        for (int i = 0; i < commands.length; ++i) {
            int st = commands[i][0];
            int en = commands[i][1];
            int k = commands[i][2];
            
            int[] arr = Arrays.copyOfRange(array, st - 1, en);
            Arrays.sort(arr);
            answer[i] = arr[k - 1];
        }
        return answer;
    }
}