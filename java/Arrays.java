

package java;

class Arrays{

    public static void main(String[] args) {
        int arr[] = new int[10];

        for(int i=0; i<10; i++){
            arr[i] = (int)Math.random();
        }

        for(int i=0; i< 10; i++){
            System.out.println(arr[i]);
        }
    }
}