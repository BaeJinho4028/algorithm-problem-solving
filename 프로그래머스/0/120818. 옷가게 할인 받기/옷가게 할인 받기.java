class Solution {
    public int solution(int price) {
        if (price >= 500000) {
            return price * 4 / 5;
        } else if (price >= 300000) {
            return price * 9 / 10;
        } else if (price >= 100000) {
            return price * 95 / 100;
        }
        return price;
    }
}