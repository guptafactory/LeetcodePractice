class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(), low = 1, mid = 0, high = n-2;
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-2] < nums[n-1]) return n-1;
        
        while(low <= high) {
            mid = low + (high - low)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid; // peak element
            else if(nums[mid] > nums[mid+1]) high = mid-1; // peak is on left (decreasing slope)
            else low = mid+1; // peak is on right (increasing slope)
        }
        return -1; // never executed
    }
};