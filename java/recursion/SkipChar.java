/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this anslate
 */
package recursion;

/**
 *
 * @author Dhiraj
 */
public class SkipChar {
    
    static String skipChars(String str ,char c , int index){
        String ans ="";
        if(index >= str.length()){
            return ans;
        }
        if (str.charAt(index) == c){
            return ans + skipChars(str, c, index+1 );
        }
        // add the character to the current answer.
        return ans + (str.charAt(index)+"") + skipChars(str , c, index+1);
    }

    public static void main(String[] args) {
        System.out.println( skipChars("hello world", 'o', 0));
        // input: str= "hello world" , c = 'o'
        // output : "hell wrld"
    }
    
}
