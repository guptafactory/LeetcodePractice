class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), low = 0, high = n-1, mid = 0, ans = INT_MAX;
        while(low <= high) {
            mid = low + (high-low)/2;
            if(nums[mid] < nums[high]) {
                ans = min(ans, nums[mid]);
                high = mid-1;
            } else {
                ans = min(ans, nums[low]);
                low = mid+1;
            }
        }
        return ans;
    }
};