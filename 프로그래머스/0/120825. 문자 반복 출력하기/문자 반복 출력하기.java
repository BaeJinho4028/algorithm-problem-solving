class Solution {
    public String solution(String my_string, int n) {
        String answer = "";
        for (String s : my_string.split("")) {
            answer += s.repeat(n);
        }
        return answer;
    }
}
