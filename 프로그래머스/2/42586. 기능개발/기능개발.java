import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] cnt = new int[100];
        int day = -1;
        
        for (int i = 0; i < progresses.length; ++i) {
            while (progresses[i] + speeds[i] * day < 100) {
                day++;
            }
            cnt[day]++;
        }
        return Arrays.stream(cnt)
            .filter(i -> i != 0)
            .toArray();
    }
}