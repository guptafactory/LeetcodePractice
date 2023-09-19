class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), low = 1, high = n-2, mid = 0;
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-2] != nums[n-1]) return nums[n-1];
        
        while(low <= high) {
            mid = low + (high-low)/2;
            if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]) return nums[mid];
            if((mid%2 == 1 && nums[mid] == nums[mid-1]) || (mid%2 == 0 && nums[mid] == nums[mid+1])) low = mid+1; // element in right half
            else high = mid-1; // element in left half
        }
        
        return -1;
    }
};