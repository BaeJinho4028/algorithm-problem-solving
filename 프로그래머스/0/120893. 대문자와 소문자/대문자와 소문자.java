class Solution {
    public String solution(String my_string) {
        String answer = "";
        for (char c : my_string.toCharArray()) {
            answer += Character.isUpperCase(c) ? Character.toLowerCase(c) : Character.toUpperCase(c); 
        }
        return answer;
    }
}