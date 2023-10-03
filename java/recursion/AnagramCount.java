
package recursion;


public class AnagramCount {
    static void count(String s , String pattern){
        int start = 0 ,end =0 , count = 0;
        int window = pattern.length();
        
        while(end < s.length()){
            if(end  - start + 1 == window){
                if(s.substring(start , end+1).equals(pattern)){
                    count++;
                }
                start++;
            }
            end++;
        }
        System.out.println(count);
    }

    public static void main(String[] args) {
        String pattern  ="for";
        String str = "forforxorforofor";
        count(str , pattern);
    }
    
}
