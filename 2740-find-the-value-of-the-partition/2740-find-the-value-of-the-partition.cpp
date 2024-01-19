class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int n = nums.size(), diff = INT_MAX;
        sort(nums.begin(), nums.end());
        // for pair x, y (where x <= y), greater values of y in nums2 and smaller values of x in nums1
        for (int i = 1; i < n; i++) diff = min(diff, nums[i] - nums[i - 1]);
        return diff;
    }
};