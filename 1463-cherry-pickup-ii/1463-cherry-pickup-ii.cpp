class Solution {
private:
    // top-down
    int func1(int i, int j1, int j2, int &n, int &m, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp) {
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return 0; // out of grid
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        if(i == n-1) { // last row
            if(j1 != j2) return grid[i][j1] + grid[i][j2]; // different cells
            else return grid[i][j1]; // same cell
        }
        int maxm = 0;
        // take maximum of 3 * 3 combinations
        for(int p = -1; p <= 1; p++) {
            for(int q = -1; q <= 1; q++) {
                if(j1 != j2) maxm = max(maxm, grid[i][j1] + grid[i][j2] + func1(i + 1, j1 + p, j2 + q, n, m, grid, dp)); // different cells
                else maxm = max(maxm, grid[i][j1] + func1(i + 1, j1 + p, j2 + q, n, m, grid, dp));
            }
        }
        return dp[i][j1][j2] = maxm;
    }
    //
    // tabulation (bottom-up) //
    int func2(vector<vector<int>>& grid, vector<vector<vector<int>>> &dp) {
        int n = grid.size(), m = grid[0].size();
        // base case
        for(int j1 = 0; j1 < m; j1++) {
            for(int j2 = 0; j2 < m; j2++) {
                if(j1 == j2) dp[n-1][j1][j2] = grid[n-1][j1];
                else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
        for(int i = n-2; i >= 0; i--) {
            for(int j1 = 0; j1 < m; j1++) {
                for(int j2 = 0; j2 < m; j2++) {
                    int maxm = 0;
                    for(int p = -1; p <= 1; p++) {
                        if(j1+p < 0 || j1+p >= m) continue;
                        for(int q = -1; q <= 1; q++) {
                            if(j2+q < 0 || j2+q >= m) continue;
                            if(j1 != j2) maxm = max(maxm, grid[i][j1] + grid[i][j2] + dp[i + 1][j1 + p][j2 + q]); // different cells
                            else maxm = max(maxm, grid[i][j1] + dp[i + 1][j1 + p][j2 + q]);
                        }
                    }
                    dp[i][j1][j2] = max(maxm, dp[i][j1][j2]);
                }
            }
        }
        // return dp[0][0][0];
        return  dp[0][0][m-1];
    }
    
    /// space optimisation ///
    int func3(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> down(m, vector<int>(m));
        vector<vector<int>> curr(m, vector<int>(m));
        for(int j1 = 0; j1 < m; j1++) {
            for(int j2 = 0; j2 < m; j2++) {
                if(j1 == j2) down[j1][j2] = grid[n-1][j1];
                else down[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
        for(int i = n-2; i >= 0; i--) {
            for(int j1 = 0; j1 < m; j1++) {
                for(int j2 = 0; j2 < m; j2++) {
                    int maxm = 0;
                    for(int p = -1; p <= 1; p++) {
                        if(j1+p < 0 || j1+p >= m) continue;
                        for(int q = -1; q <= 1; q++) {
                            if(j2+q < 0 || j2+q >= m) continue;
                            if(j1 != j2) maxm = max(maxm, grid[i][j1] + grid[i][j2] + down[j1 + p][j2 + q]); // different cells
                            else maxm = max(maxm, grid[i][j1] + down[j1 + p][j2 + q]);
                        }
                    }
                    curr[j1][j2] = maxm;
                }
            }
            down = curr;
        }
        return down[0][m-1];
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        // int dp[n][m][m]
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        // return func1(0, 0, m-1, n, m, grid, dp);
        // return func2(grid, dp);
        return func3(grid);
    }
};