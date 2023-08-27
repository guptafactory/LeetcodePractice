class Solution {
private:
    // memoisation (top-down)
    int func1(int ind, vector<int> &nums, vector<int> &dp) {
        if (ind == 0)
            return nums[ind];
        if (ind < 0)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int pick = nums[ind] + func1(ind - 2, nums, dp);
        int not_pick = func1(ind - 1, nums, dp);

        return dp[ind] = max(pick, not_pick);
    }
    
    // tabulation (bottom-up)
    int func2(vector<int> &nums, vector<int> &dp) {
        int n = nums.size(), pick = 0, not_pick = 0;
        dp[0] = nums[0];
        if (n > 1)
            dp[1] = nums[1];
        for (int i = 2; i < n; i++)
        {
            pick = nums[i] + dp[i - 2];
            not_pick = dp[i - 1];
            dp[i] = max(pick, not_pick);
        }
        return dp[n - 1];
    }
    
    // space optimised
    int func3(vector<int> &nums, vector<int> &dp) {
        int n = nums.size(), prev_2 = 0, prev = 0, curr = 0, pick = 0, not_pick = 0;
        prev_2 = 0;
        prev = nums[0];
        for (int i = 1; i < n; i++) {
            pick = nums[i];
            if(i > 1) pick += prev_2;
            not_pick = prev;
            curr = max(pick, not_pick);
            prev_2 = prev;
            prev = curr;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        // return func1(n - 1, nums, dp);
        // return func2(nums, dp);
        return func3(nums, dp);
    }
};