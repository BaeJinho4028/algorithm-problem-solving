import java.util.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int time = 0;
        int idx = 0;
        int w = 0;
        Queue<Integer> q = new LinkedList<>();
        
        while (idx < truck_weights.length) {
            time++;
            
            if (q.size() == bridge_length) {
                w -= q.peek(); 
                q.poll();
            }
            
            if (w + truck_weights[idx] <= weight) {
                w += truck_weights[idx];
                q.offer(truck_weights[idx++]);
            } else {
                q.offer(0);
            }
        }
        return time + bridge_length; // 맨마지막 트런 건너는 시간 추가
    }
}
