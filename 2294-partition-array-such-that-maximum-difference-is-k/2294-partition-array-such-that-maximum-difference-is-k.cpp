class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), last = nums[0], ans = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] - last <= k) continue;
            else { ans++; last = nums[i]; }
        }
        return ans;
    }
};