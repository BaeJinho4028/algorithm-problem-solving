import java.util.*;

class Solution {
    public long solution(String numbers) {
        Map<String, String> WORD_TO_DIGIT = Map.of(
            "zero", "0",
            "one", "1",
            "two", "2",
            "three", "3",
            "four", "4",
            "five", "5",
            "six", "6",
            "seven", "7",
            "eight", "8",
            "nine", "9"
        );
        
        for (Map.Entry<String, String> entry : WORD_TO_DIGIT.entrySet()) {
            numbers = numbers.replaceAll(entry.getKey(), entry.getValue());
        }
        return Long.parseLong(numbers);
    }
}