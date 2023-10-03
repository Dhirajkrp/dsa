
package recursion;

import java.util.Arrays;

public class MergeSort {
        private static int[] merge(int[] first, int[] second) {
            int mix[] = new int[first.length + second.length];
            int i = 0 ,j=0, k=0;
            
            while(i < first.length && j<second.length){
                if(first[i]<= second[j]){
                    mix[k] = first[i];
                    i++;
                }
                else{
                    mix[k] = second[j];
                    j++;
                }
                k++;
            }
            while(i<first.length){
                mix[k] = first[i];
                i++;
                k++;
            }
            while(j<second.length){
                mix[k] = second[j];
                j++;
                k++;
            }
            return mix;
        }

    private static int[] sort(int[] arr){
        
        if(arr.length==1){
            return arr;
        }
        int mid  =arr.length/2;
        int left[]= sort(Arrays.copyOfRange(arr, 0, mid));
        int right[]= sort(Arrays.copyOfRange(arr, mid, arr.length));
        
        
        return merge(left ,right);
    }

    public static void main(String[] args) {
        int arr[]  ={5,4,1,8,15};
        int ans[] = sort(arr);
        for(int i: ans){
            System.out.print(i+" ");
        }
        System.out.println("");
    }


    
}
