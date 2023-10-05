
package sliding_window;

import java.util.ArrayList;
import java.util.List;



public class MaxofSubArrays {

    static List max(int[] arr , int k){
        ArrayList<Integer> list = new ArrayList<>();
         int start = 0, end = 0;
        int window  = k;
        int max = -99;
        
        while(end < arr.length){
            if(arr[end] > max){
                max = arr[end];
            }
            
            if(end -start +1 == window){
                System.out.println("["+ arr[start]+","+ arr[start+1] +","+ arr[end] +"," + "] :"+max);
                list.add(max);
                if(max == arr[start]){
                    max = arr[start+1];
                }
                start++;
            }
            end++;
        }
        return list;
        
    } 

    public static void main(String[] args) {
        int arr[] = {1,3,-1,-3,5 ,3,6,7};
        int k= 3;
        System.out.println(max(arr , k));  
    }
    
}
