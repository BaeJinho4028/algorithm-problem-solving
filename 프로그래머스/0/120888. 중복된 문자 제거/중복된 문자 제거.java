class Solution {
    public String solution(String my_string) {
        StringBuilder sb = new StringBuilder();
        
        for (char c : my_string.toCharArray()) {
            if (sb.indexOf(String.valueOf(c)) == -1) {
                sb.append(c);
            }
        }
        return sb.toString();
    }
}