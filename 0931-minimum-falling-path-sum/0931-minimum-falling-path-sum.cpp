class Solution {
private:
    int func1(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(i == 0) return matrix[0][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];
        
        int down = matrix[i][j] + func1(i-1, j, n, matrix, dp);
        int down_left = j != 0 ? matrix[i][j] + func1(i-1, j-1, n, matrix, dp) : INT_MAX;
        int down_right = j != n-1 ? matrix[i][j] + func1(i-1, j+1, n, matrix, dp) : INT_MAX;
        
        return dp[i][j] = min(min(dp[i][j], down), min(down_left, down_right));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        int ans = INT_MAX;
        for(int i = n-1, j = 0; j < n; j++) {
            ans = min(ans, func1(i, j, n, matrix, dp));
        }
        return ans;
    }
};