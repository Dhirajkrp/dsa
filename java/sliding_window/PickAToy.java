
package sliding_window;
import java.util.HashMap;
public class PickAToy {

    private static void max(String s){
        
        int start = 0,end  =0 ,length =0 , maxLength =0;
        
        HashMap<Character , Integer> map = new HashMap();
        int uniqueChars = 0; 
        
        while(end < s.length()){
            char c = s.charAt(end);
            if(map.containsKey(c)){
                
                if(map.get(c) == 0){
                    uniqueChars++;
                }
                map.put(c, map.get(c) +1);
                length++;
            }
            else{
                map.put(c, 1);
                uniqueChars ++;
                length++;
            }
            if(uniqueChars == 2 && length > maxLength){
                maxLength = length;
                System.out.println(s.substring(start , end+1));
            }
            if(uniqueChars > 2){
                while (uniqueChars> 2){
                    char st = s.charAt(start);
                    map.put(st , map.get(st)-1);
                    
                    if(map.get(st) == 0){
                        uniqueChars--;    
                    }
                    length--;
                    start++;
                }  
            } 
            end++;
        }
   
        System.out.println(map);
       
    }

    public static void main(String[] args) {
        String toys = "abaccab";
        
        max(toys);
    }
    
}
