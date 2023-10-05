
package recursion;

import java.util.HashSet;


public class LongestSubstringWithNoRepeatingChars {
    static void max (String s){
        HashSet<Character> set  = new HashSet<>();
        int start =0 , end = 0;
        String ans = "";
        int maxLength = 0;
        
        while(end < s.length()){
            
            if(! set.add(s.charAt(end))){
                while(! set.add(s.charAt(end))){
                    set.remove(s.charAt(start));
                    start++;
                }
            }
            if(set.size() > maxLength){
                maxLength = set.size();
            }
           
            end++;
        }
        System.out.println(maxLength);
    }
    public static void main(String[] args) {
        String s = "abaafgreehiie";
        max(s);
    }
    
}
