
package sliding_window;

import java.util.HashMap;

public class MinimumWIndowSubstring {
    
    static void min(String s , String t){
        int min = 9999;
        int length=0;
        HashMap<Character, Integer> map = new HashMap<>();
        for(char c: t.toCharArray()){
            if(map.containsKey(c)){
                map.put(c, map.get(c)+1);
                length++;
            }
            else{
                map.put(c , 1);
                length++;
            }
        }
        int rem = map.size();
        
        int start = 0,end= 0;
        while(end< s.length()){
            char c = s.charAt(end);
            if(map.containsKey(c)){
                map.put(c, map.get(c)-1);
                length--;
                if(map.get(c) == 0){
                    rem--;
                }
            }
            
            if(rem ==0 && end-start+1 < min){
                while(length < 0 ){
                    char st = s.charAt(start);
                    if(map.containsKey(st)){
                        start++;
                        map.put(st,map.get(st)+1);
                        length++;   
                    }            
                }
                while(! map.containsKey(s.charAt(start))){
                    start++;
                }
                System.out.println(s.substring(start, end+1));

                min = end-start+1;
            }
            end++;
        }   
    }
    public static void main(String[] args) {
        String s = "timetopractice";
        String t = "toc";
        min(s,t);
    }
    
}
