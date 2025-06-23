class Solution {
    public int solution(int balls, int share) {
        int k = Math.min(share, balls - share);
        long answer = 1;
        for (int i = 1; i <= k; ++i) {
            answer = answer * (balls - k + i) / i;
        }
        return (int) answer;
    }
}