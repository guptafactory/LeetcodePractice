class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // left values are increasing fashion & right values are decreasing fashion
        int low = 1, mid = 0, high = arr.size() - 2;
        while(low <= high) {
            mid = low + (high - low)/2;
            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) return mid; // mountain peek value
            else if(arr[mid-1] < arr[mid]) low = mid+1; // ans is on right
            else if(arr[mid] > arr[mid+1]) high = mid-1; // ans is on left
        }
        return -1;
    }
};