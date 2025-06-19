class Solution {
    public int solution(int n) {
        int x = (int) Math.sqrt(n);
        return (x * x == n) ? 1 : 2;
    }
}