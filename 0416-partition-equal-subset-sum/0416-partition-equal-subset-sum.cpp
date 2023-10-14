class Solution {
private:
    bool func1(int ind, int target, vector<int> &arr, vector<vector<int>> &dp) {
        if(target == 0) return true;
        if(ind == 0) return (arr[0] == target);
        if(dp[ind][target] != -1) return dp[ind][target];
        bool not_pick = func1(ind-1, target, arr, dp);
        bool pick = false;
        if(target >= arr[ind]) pick = func1(ind-1, target-arr[ind], arr, dp);
        return dp[ind][target] = pick | not_pick;
    }
    // bottom-up
    bool func2(int &n, int &target, vector<int> &arr) {
        vector<vector<bool>> dp(n, vector<bool>(target+1, false));
        for(int i = 0; i < n; i++) dp[i][0] = true; // target == 0 at any array index
        if(arr[0] == target) dp[0][arr[0]] = true; // at index 0, target == arr[0]
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= target; j++) {
               bool not_pick = dp[i-1][j];
               bool pick = false;
               if(j >= arr[i]) pick = dp[i-1][j-arr[i]];
               dp[i][j] = pick | not_pick; 
            }
        }
        return dp[n-1][target];
    }
    // space-optimisation
    bool func3(int &n, int &target, vector<int> &arr) {
        vector<bool> prev(target+1, false), curr(target+1, false);
        prev[0] = curr[0] = true; // target == 0
        if(arr[0] == target) prev[arr[0]] = true; // at index 0, target == arr[0]
        for(int i = 1; i < n; i++) {
            curr[0] = true;
            for(int j = 1; j <= target; j++) {
               bool not_pick = prev[j];
               bool pick = false;
               if(j >= arr[i]) pick = prev[j-arr[i]];
               curr[j] = pick | not_pick;
            }
            prev = curr;
        }
        return prev[target];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2) return false;
        int n = nums.size(), target = sum / 2;
        // vector<vector<int>> dp(n, vector<int>(target +1, -1));
        // return func1(n-1, target, nums, dp);
        // return func2(n, target, nums);
        return func3(n, target, nums);
    }
};