
package recursion;

import java.util.HashMap;


public class CompleteAnagramCount {
    
    static void count(String s , String pattern){
        
        HashMap<Character , Integer> map = new HashMap<>();
        int charCount = pattern.length();
        int leftChars = 0;
        int start = 0, end =0, count = 0;
        int window = pattern.length();
        
        //initializing the map for storing the unique characters and their no of occurence.
        for(char c: pattern.toCharArray()){
            if(map.containsKey(c)){
                map.put(c , map.get(c)+1);
                
            }else{
                map.put(c , 1);
                leftChars ++;
            }  
        }

        while(end < s.length()){
            char c = s.charAt(end);
            if(map.containsKey(c)){
                map.put(c , map.get(c)-1);
                if(map.get(c) == 0){
                    leftChars--;
                }
            }
            if(end - start +1 == window){
                if(leftChars ==0){
                    System.out.println(s.substring(start , end+1));
                }
                c = s.charAt(start);
                if(map.get(c) == 0){
                    leftChars++;
                }
                map.put(c , map.get(c)+1);
                start++;
            }
            end++;
        }
    }
    
    public static void main(String[] args) {
        String pattern = "aaba";
        String s = "aabaabaa";
        count(s, pattern);
        
    }
    
}
