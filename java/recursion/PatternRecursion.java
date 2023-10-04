
package recursion;

import java.util.Arrays;

public class PatternRecursion {

static void printStar(int n){
    
    if(n<=0){
        return;
    }
    for(int i= 0 ;i < n ;i++){
        System.out.print("*");
    }
    System.out.println("");
    printStar(n-1);
}

static void triangle(int r ,int c){
    if(r ==0) return;
    
    if(c < r){
        System.out.print("*");
        triangle(r, c+1);
    }
    else{
        System.out.println("");
        triangle(r-1,0);
    } 
}

static void triangle2(int r ,int c){
    if(r ==0) return;
    
    if(c < r){
        triangle2(r, c+1);
        System.out.print("*");   
    }
    else{ 
        triangle2(r-1,0);
        System.out.println("");
        
    } 
}

static void selection(int[] arr ,int current , int length, int max){
    
    if(length ==1) return;
    
    //this indicates we are still searching for the max in the current pass.
    if(current <length){
        if(arr[current] > arr[max] ) 
            selection(arr,current+1,length , current);
        else
            selection(arr, current +1, length, max);
    }
    //this indicates we have found the max,now we need to swap and sort the subarray of length n-1.
    else{
        int temp = arr[max];
        arr[max] = arr[length-1];
        arr[length-1] = temp;
        selection(arr, 0, length-1, 0);
    }
}



    public static void main(String[] args) {
        int[] arr = {9,3,7,5};
        selection(arr, 0, arr.length, 0);
        System.out.println(Arrays.toString(arr));
    
    }


}
