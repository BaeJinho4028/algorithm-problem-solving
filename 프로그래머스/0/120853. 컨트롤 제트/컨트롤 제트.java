class Solution {
    public int solution(String s) {
        int answer = 0;
        int pre = -1;
        for (String token : s.split(" ")) {
            if (token.equals("Z")) {
                answer -= pre;
            } else {
                pre = Integer.parseInt(token);
                answer += pre;
            }
        }
        return answer;
    }
}