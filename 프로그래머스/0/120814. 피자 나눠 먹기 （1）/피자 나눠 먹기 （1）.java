class Solution {
    public int solution(int n) {
        int tmp = n % 7 == 0 ? 0 : 1;
        return n / 7 + tmp;
    }
}