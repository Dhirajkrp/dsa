
package recursion;

import java.util.HashMap;

public class LongestSubstringwithKUniqueChars {
    static void max(String s , int k){
        int start =0 ,end = 0 ;
        int uniqueChars = 0 , length = 0 , maxLength =0;
        String ans = "";
    
    HashMap<Character,Integer> map = new HashMap<>();
    
    while(end < s.length()){
        
        char c = s.charAt(end);
        if(map.containsKey(c)){
            if(map.get(c) ==0){
                uniqueChars++;
            }
            map.put(c,map.get(c)+1);
            length++;
        }
        else{
            map.put(c, 1);
            uniqueChars++;
            length++;
        }
        
        if(uniqueChars >k){
            
            while(uniqueChars > k){
               char st = s.charAt(start);
               map.put(st, map.get(st)-1);
               length--;
               if(map.get(st) == 0){
                   uniqueChars--;
               }
               start++;
            }
        }
        
        if(uniqueChars == k && maxLength < length){
            maxLength = length;
            ans = s.substring(start , end+1);
        }
        end++;
        
    }

        System.out.println(ans);

    }
    public static void main(String[] args) {
        String s = "aabacbebghebe";
        int k  =2;
        
        max(s,k);
    }
}
