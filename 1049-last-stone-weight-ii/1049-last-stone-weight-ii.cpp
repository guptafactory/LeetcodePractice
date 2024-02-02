class Solution {
    void subsetSum(int &n, int &sum, vector<int> &arr, vector<vector<bool>> &dp) {
        for (int j = 0; j <= sum; j++) dp[0][j] = false;
        for (int i = 0; i <= n; i++) dp[i][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i - 1] <= j) dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                else dp[i][j] = dp[i - 1][j];
            }
        }
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size(), tot_sum = 0;
        for (int i = 0; i < n; i++) tot_sum += stones[i];
        vector<vector<bool>> dp(n + 1, vector<bool>(tot_sum + 1));
        subsetSum(n, tot_sum, stones, dp);
        for (int s = tot_sum / 2; s >= 0; s--) {
            if (dp[n][s]) return tot_sum - 2 * s;
        }
        return 0;
    }
};