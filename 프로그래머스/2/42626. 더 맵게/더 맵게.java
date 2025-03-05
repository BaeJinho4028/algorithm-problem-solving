import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        Queue<Integer> pq = new PriorityQueue<>(scoville.length);
        for (int s : scoville) {
            pq.offer(s);
        }
        
        while (pq.peek() < K) {
            if (pq.size() == 1) {
                return -1;
            }
            int a = pq.poll();
            int b = pq.poll();
            pq.offer(a + b  * 2);
            answer++;
        }
        return answer;
    }
}