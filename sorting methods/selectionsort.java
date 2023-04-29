
import java.util.Arrays;

public class selectionsort {
    public static void sort(int arr[]) {
        int i,j;
        int a,b;
        for (i=0;i<arr.length;i++){
            a=i;
            for (j=i+1;j<arr.length;j++){
                if (arr[a]>arr[j]){
                    a=j;
                }
                b=arr[i];
                arr[i]=arr[a];
                arr[a]=b;
            }
        }
    }
    public static void main(String[] args) {
        int arr[]={1,233,45,4444,55};
        sort(arr);
        System.out.println(Arrays.toString(arr));

    }
}
