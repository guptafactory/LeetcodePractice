class Solution {
private:
    // top-down
    int func1(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(i == 0) return matrix[0][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];
        
        int down = matrix[i][j] + func1(i-1, j, n, matrix, dp);
        int down_left = j != 0 ? matrix[i][j] + func1(i-1, j-1, n, matrix, dp) : INT_MAX;
        int down_right = j != n-1 ? matrix[i][j] + func1(i-1, j+1, n, matrix, dp) : INT_MAX;
        
        return dp[i][j] = min(min(dp[i][j], down), min(down_left, down_right));
    }
    // tabulation(bottom-up)
    int func2(vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size();
        for(int j = 0; j < n; j++) dp[0][j] = matrix[0][j]; // initialising 1st row
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int down = matrix[i][j] + dp[i-1][j];
                int down_left = j != 0 ? matrix[i][j] + dp[i-1][j-1] : INT_MAX;
                int down_right = j != n-1 ? matrix[i][j] + dp[i-1][j+1] : INT_MAX;

                dp[i][j] = min(min(dp[i][j], down), min(down_left, down_right));
            }
        }
        int ans = INT_MAX;
        for(int j = 0; j < n; j++) ans = min(ans, dp[n-1][j]);
        return ans;
    }
    // optimisation
    int func3(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n), present(n);
        for(int j = 0; j < n; j++) prev[j] = matrix[0][j]; // initialising 1st row
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int down = matrix[i][j] + prev[j];
                int down_left = j != 0 ? matrix[i][j] + prev[j-1] : INT_MAX;
                int down_right = j != n-1 ? matrix[i][j] + prev[j+1] : INT_MAX;
                
                present[j] = min(down, min(down_left, down_right));
            }
            prev = present;
        }
        int ans = INT_MAX;
        for(int x: prev) ans = min(x, ans);
        return ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        int ans = INT_MAX;
        for(int i = n-1, j = 0; j < n; j++) {
            ans = min(ans, func1(i, j, n, matrix, dp));
        }
        // return ans;
        // return func2(matrix, dp);
        return func3(matrix);
    }
};