/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
int peakIdx(MountainArray &arr) {
    int low = 1, mid = 0, high = arr.length() - 2, val = 0, val_prev = 0, val_next = 0;
    
    while(low <= high) {
        mid = low + (high - low)/2;
        
        val_prev = arr.get(mid-1);
        val = arr.get(mid);
        val_next = arr.get(mid+1);
        
        if(val_prev < val && val > val_next) return mid; // mountain peek value
        else if(val_prev < val) low = mid+1; // ans is on right
        else if(val > val_next) high = mid-1; // ans is on left
    }
    return -1;
}
int peakLeft(int target, MountainArray &arr, int low, int high) {
    int mid = 0, val = 0;
    while(low <= high) {
        mid = low + (high-low)/2;
        val = arr.get(mid);
        
        if(val == target) return mid;
        else if(val > target) high = mid-1;
        else low = mid+1;
    }
    return -1;
}
int peakRight(int target, MountainArray &arr, int low, int high) {
    int mid = 0, val = 0;
    while(low <= high) {
        mid = low + (high-low)/2;
        val = arr.get(mid);
        
        if(val == target) return mid;
        else if(val > target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length(), ans = -1;
        // find peak element
        int peak = peakIdx(arr);
        
        ans = peakLeft(target, arr, 0, peak);
        if(ans != -1) return ans;
        
        ans = peakRight(target, arr, peak + 1, n-1);
        return ans;
    }
};