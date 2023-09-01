class Solution {
private:
    // top-down
    int func1(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        if(i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = func1(i-1, j, obstacleGrid, dp);
        int left = func1(i, j-1, obstacleGrid, dp);
        
        return dp[i][j] = left + up;
    }
    // bottom-up
    int func2(int &m, int &n, vector<vector<int>> &obstacleGrid, vector<vector<int>>& dp) {
        if(obstacleGrid[0][0] == 1) return 0;
        int up = 0, left = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else if(i == 0 && j == 0) dp[0][0] = 1;
                else {
                    up = 0; left = 0;
                    if(i != 0) up = dp[i-1][j];
                    if(j != 0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
    // space optimised
    int func3(int &m, int &n, vector<vector<int>> &obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;
        vector<int> prev(n, 0), curr(n, 0);
        int up = 0, left = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(obstacleGrid[i][j] == 1) curr[j] = 0;
                else if(i == 0 && j == 0) curr[0] = 1;
                else {
                    up = 0; left = 0;
                    if(i != 0) up = prev[j];
                    if(j != 0) left = curr[j-1];
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        
        return prev[n-1];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // return func1(m-1, n-1, obstacleGrid, dp);
        // return func2(m, n, obstacleGrid, dp);
        return func3(m, n, obstacleGrid);
        
    }
};