class Solution {
private:
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
    // tabulation (bottom-up)
    // int func2()
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        // int dp[n][m][m]
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return func1(0, 0, m-1, n, m, grid, dp);
        // return func2();
    }
};