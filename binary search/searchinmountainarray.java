// package binary search;

// public class searchinmountainarray {
    
// }


class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int n = mountainArr.length();
        int peakIndex = findPeakIndex(mountainArr, 0, n - 1);
        
        int index = binarySearch(mountainArr, target, 0, peakIndex, true);
        if (index != -1) {
            return index;
        }
        
        return binarySearch(mountainArr, target, peakIndex + 1, n - 1, false);
    }
    
    private int findPeakIndex(MountainArray mountainArr, int left, int right) {
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    
    private int binarySearch(MountainArray mountainArr, int target, int left, int right, boolean increasing) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midValue = mountainArr.get(mid);
            if (midValue == target) {
                return mid;
            }
            if ((midValue < target) == increasing) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
}
