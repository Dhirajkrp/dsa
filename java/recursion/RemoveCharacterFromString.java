
package recursion;

import java.util.ArrayList;

public class RemoveCharacterFromString {

    static String removeChar(String s , int index , char c  ,StringBuilder ans){

        if(index == s.length()){
            return ans+"";
        }
        if(s.charAt(index) != c){
            ans.append(s.charAt(index));
        }
        return removeChar(s,index+1 , c,ans);   
    } 
    
    static String remove(String s , int index , char c){

        if(index == s.length()){
            return "";
        }
        if(s.charAt(index) != c){
            return s.charAt(index) + remove(s,index+1 , c);
        }
        return remove(s,index+1,c);   
    } 
    
        static String removeCharacter(String s , char c){

        if(s.length() == 0){
            return s;
        }
        if(s.charAt(0) != c){
            return s.charAt(0) + removeCharacter(s.substring(1) , c);
        }
        return removeCharacter(s.substring(1) , c);   
    } 
        
    static String removeSubString(String str , String substr){
        
        if(str.length() < substr.length()){
            return str;
        }
        if(str.startsWith(substr)){
            return removeSubString(str.substring(substr.length()) , substr);
        }
        return str.charAt(0) + removeSubString(str.substring(1), substr);
    }
    static String replacestr(String inputStr , String seq , String newSeq){
        
        if(inputStr.length() < seq.length()){
            return inputStr;
        }
        if(inputStr.startsWith(seq)){
            return replacestr(newSeq +inputStr.substring(seq.length()), seq , newSeq);
        }
        return inputStr.charAt(0) + replacestr(inputStr.substring(1), seq , newSeq);
    }
    
    static void subseq(String p , String up){
        if(up.isEmpty()){
            System.out.println(p);
            return;
        }
        char ch  = up.charAt(0);
        subseq(p+ch , up.substring(1));
        subseq(p, up.substring(1));
        
    }
    
    static ArrayList<String> subSeq(String p , String up){
        ArrayList<String> list = new ArrayList();
        if(up.isEmpty()){
            list.add(p);
            return list;
        }
        char ch  = up.charAt(0);
        
        list.addAll( subSeq(p +ch, up.substring(1)));
        list.addAll( subSeq(p , up.substring(1)));
        return list;
        
    }
    private static void subsets(String s){
        ArrayList<String> list  = new ArrayList();
        ArrayList<String> temp = new ArrayList();
        list.add("");
        for(char c: s.toCharArray()){ 
            for(String elem: list){
                temp.add(elem+c);
            }
            list.addAll(temp);
            temp.clear();
        }
        list.remove("");
        System.out.println(list);
    }


    public static void main(String[] args) {
        String str = "I want to eat apple pie, and some chips";
        String seq = "pie";
        String newSeq = "cake";
        
//        System.out.println(replacestr(str ,seq , newSeq));
//        subseq("", "abc");
//System.out.println(subSeq("" , "abc"));
        subsets("abc");
        
    }
}

