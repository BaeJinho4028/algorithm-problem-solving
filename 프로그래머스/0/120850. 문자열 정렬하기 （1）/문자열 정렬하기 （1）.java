class Solution {
    public int[] solution(String my_string) {
        return my_string.chars()
            .filter(Character::isDigit)
            .map(c -> c - '0')
            .sorted()
            .toArray();
    }
}