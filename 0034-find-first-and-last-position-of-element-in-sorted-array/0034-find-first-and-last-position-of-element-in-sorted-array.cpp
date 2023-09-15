class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int x = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(n == 0 || x == n || nums[x] != target) return {-1, -1};
        int y = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        
        return {x, y};
    }
};