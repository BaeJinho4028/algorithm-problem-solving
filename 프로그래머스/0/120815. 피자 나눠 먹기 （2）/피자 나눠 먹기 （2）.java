class Solution {
    private int gcd(int a, int b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }
    
    public int solution(int n) {
        return n / gcd(n, 6);
    }
}