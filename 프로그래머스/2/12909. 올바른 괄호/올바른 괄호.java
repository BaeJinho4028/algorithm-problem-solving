class Solution {
    boolean solution(String s) {
        int n = 0;
        for (char c : s.toCharArray()) {
            if(n < 0) {
                return false;
            } else if (c == '(') {
                ++n;
            } else if (c == ')') {
                --n;
            }
        }

        return (n == 0);
    }
}