// //myappraoch
// import java.utils.*;
// public class hello{
//     public static void main(String[] args) {
//         int []arr={1,3,5,6,4,2,0};
//         int a=mountainarray(arr);
//         System.out.println(arr[a]+" "+a);
        
//     }
//     public static int mountainarray(int []arr) {
    
//         int mid;
//         int left=0;
//         int right=arr.length-1;
//         while (left<=right){
//             mid= (left+right)/2;
//             if( (arr[mid-1]<arr[mid]) &&(arr[mid]<arr[mid+1])){
//                 left=mid+1;
//             }
//             else if ( (arr[mid-1]>arr[mid]) &&(arr[mid]>arr[mid+1])){
//                 right=mid-1;

//             }
//             else if ( (arr[mid-1]<arr[mid]) &&(arr[mid]>arr[mid+1])){
//                 return mid;
//             }

//         }
//         return -1;
//     }
// }


//chatgpt
// public static int findPeakElement(int[] arr) {
//     int n = arr.length;
//     if (n < 3) {
//         throw new IllegalArgumentException("Input array must have at least 3 elements.");
//     }
//     int left = 0, right = n - 1;
//     while (left < right) {
//         int mid = left + (right - left) / 2;
//         if (arr[mid] < arr[mid + 1]) {
//             left = mid + 1;
//         } else {
//             right = mid;
//         }
//     }
//     return left;
// }





