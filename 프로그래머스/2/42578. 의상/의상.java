import java.util.*;

class Solution {
    public int solution(String[][] clothes) {        
        Map<String, Integer> map = new HashMap<>();
        for (var c : clothes) {
            map.put(c[1], map.getOrDefault(c[1], 0) + 1);
        }
        
        int answer = 1;
        for (var m : map.values()) {
            answer *= (m + 1);
        }
        
        return answer - 1;
    }
}