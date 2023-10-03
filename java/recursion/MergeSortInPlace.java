
package recursion;

import java.util.Arrays;
public class MergeSortInPlace {
    static void  sort(int arr[] , int start , int end){
        
        if(end-start ==1){
            return ;
        }
        int mid = (end+start)/2;
        sort(arr,start,mid);
        sort(arr,mid,end);
        
        merge(arr, start ,mid,end);
        
    }
    static void merge(int arr[] , int start, int mid,int end ){
        int i = start, j = mid , k =0;
        int[] mix = new int[end-start];
        
        while(i< mid && j< end){
            if(arr[i] <arr[j]){
                mix[k] = arr[i];
                i++;
            }
            else{
                mix[k] = arr[j];
                j++;
            }
            k++;
        }
        while(i <mid){
            mix[k] = arr[i];
            i++;
            k++;
        }
        while(j <end){
            mix[k] = arr[j];
            j++;
            k++;
        }
        for(int l= 0 ;l<mix.length;l++){
            arr[start+l] = mix[l];
        }
        
    }
    public static void main(String[] args) {
        int arr[] = {3,4,1,7,2};
        sort(arr,0,arr.length);
        System.out.println(Arrays.toString(arr));
        
    }
    
}
