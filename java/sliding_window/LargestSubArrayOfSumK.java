
package sliding_window;


public class LargestSubArrayOfSumK {
    private static void max(int[] arr, int k) {
        
        int start =0 ,end = 0, sum = 0;
        int ans = 0;
        
        while(end < arr.length){
            sum+= arr[end];
            if(sum >k){
                while(sum > k){
                    sum -= arr[start];
                    start++;
                }
            }
            if(sum ==k && ans < end-start+1){
                ans = end-start+1; // end-start+1 => size of the window.
            }
            end++;   
        }

        System.out.println("Max Length : "+ ans);
    }
    public static void main(String[] args) {
        int arr[] = {15,1,1,1,2,3,5};
        int k  = 10;
        max(arr , k);
    }


    
}
