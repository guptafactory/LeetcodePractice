class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), low = 0, mid = 0, high = n-1;
        while(low <= high) {
            mid = low + (high - low)/2;
            if(nums[mid] == target) return mid;
            // find sorted-halve to compare the target value
            // check if left halve is sorted
            if(nums[low] <= nums[mid]) {
                if(nums[low] <= target && nums[mid] >= target) high = mid-1; // exist in left sorted halve
                else low = mid+1; // not exist in left sorted halve
            }
            else {
                if(nums[mid] <= target && target <= nums[high]) low = mid+1;
                else high = mid-1;
            }
        }
        return -1;
    }
};