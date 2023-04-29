public class rotatedsortedarraysearch {
    public static int specbinarysearch(int []arr,int target,int r,int l){
        while (l<= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;    
    
    }

    public static int pivotelem(int arr[]) {
        int n = arr.length;
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;

    }
    public static int rotatedarraysearch(int arr[],int target) {
        int a=pivotelem(arr);
        int b;
        if ((arr[0]<target) && (target<arr[a])){
            b=specbinarysearch(arr, target, a, 0);
        }
        else {
            b=specbinarysearch(arr, target, arr.length-1, a+1);
        }
        return b;
    }
    public static void main(String[] args) {
        int arr[]={4,5,6,7,0,1,2};
        int target=3;
        int a=rotatedarraysearch(arr, target);
        System.out.println(a);
    }
}
