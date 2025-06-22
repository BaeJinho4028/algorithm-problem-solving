import java.util.*;

class Solution {
    public int[] solution(int[] emergency) {
        int n = emergency.length;
        int[] answer = new int[n];
        
        List<Integer> sorted = new ArrayList<>();
        for (int num : emergency) {
            sorted.add(num);
        }
        Collections.sort(sorted, Collections.reverseOrder());
        
        for (int i = 0; i < n; ++i) {
            answer[i] = sorted.indexOf(emergency[i]) + 1;
        }
        return answer;
    }
}