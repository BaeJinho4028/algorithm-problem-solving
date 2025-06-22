class Solution {
    public String solution(int age) {
        StringBuilder sb = new StringBuilder();
        String s = String.valueOf(age);
        for (char c : s.toCharArray()) {
            sb.append((char)('a' + (c - '0')));
        }
        return sb.toString();
    }
}