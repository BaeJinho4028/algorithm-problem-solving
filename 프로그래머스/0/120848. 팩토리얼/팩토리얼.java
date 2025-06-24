class Solution {
   public int solution(int n) {
        int answer = 1;
        int f = 1;
        while(n >= f) {
            answer++;
            f *= answer;
        }
        return answer -1 ;
    }
}