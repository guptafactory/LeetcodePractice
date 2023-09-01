class Solution {
private:
    int func1(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp) {
        if(i == 0 && j == 0) return grid[0][0];
        else if(i < 0 || j < 0) return INT_MAX;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = INT_MAX, left = INT_MAX;
        if(i != 0) up = grid[i][j] + func1(i-1, j, grid, dp);
        if(j != 0) left = grid[i][j] + func1(i, j-1, grid, dp);
        
        return dp[i][j] = min(up, left);
    }
    int func2(vector<vector<int>>& grid, vector<vector<int>> dp) {
        int m = grid.size(), n = grid[0].size(), up = 0, left = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) dp[i][j] = grid[0][0];
                else {
                    up = INT_MAX; left = INT_MAX;
                    if(i != 0) up = grid[i][j] + dp[i-1][j];
                    if(j != 0) left = grid[i][j] + dp[i][j-1];
                    dp[i][j] = min(up, left);
                }
            }
        }
        
        return dp[m-1][n-1];
    }
    int func3(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), up = 0, left = 0;
        vector<int> prev(n, 0), curr(n, 0);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) curr[j] = grid[0][0];
                else {
                    up = INT_MAX; left = INT_MAX;
                    if(i != 0) up = grid[i][j] + prev[j];
                    if(j != 0) left = grid[i][j] + curr[j-1];
                    curr[j] = min(up, left);
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        // return func1(m-1, n-1, grid, dp);
        // return func2(grid, dp);
        return func3(grid);
        
    }
};