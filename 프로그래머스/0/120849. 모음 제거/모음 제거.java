class Solution {
    public String solution(String my_string) {
        String[] aeiou = {"a","e","i","o","u"};
        for(String ae : aeiou){
            my_string = my_string.replace(ae,"");
        }

        return my_string;    
    }
}