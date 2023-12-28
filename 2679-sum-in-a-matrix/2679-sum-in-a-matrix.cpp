class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size(), maxm = 0, ans = 0;
        for (int i = 0; i < n; i++) sort(nums[i].begin(), nums[i].end());
        for (int j = 0; j < m; j++) {
            maxm = 0;
            for (int i = 0; i < n; i++) maxm = max(maxm, nums[i][j]);
            ans += maxm;
        }
        return ans;
    }
};