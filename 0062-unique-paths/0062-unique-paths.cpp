class Solution {
private:
    // top-down approach
    int func1(int i, int j, vector<vector<int>> &dp) {
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j]; // up
        int ans = 0;
        ans += func1(i-1, j, dp); // up
        ans += func1(i, j-1, dp); // left
        return dp[i][j] = ans;
    }
    // bottom-up approach
    int func2(int &m, int &n, vector<vector<int>> &dp) {
        int up = 0, left = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) dp[i][j] = 1;
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
    // space optimisation
    int func3(int &m, int &n) {
        int ans = 0, up = 0, left = 0;
        vector<int> prev(n, 0), curr(n, 0);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) curr[j] = 1;
                else {
                    ans = 0; up = 0; left = 0;
                    if(i != 0) up = prev[j];
                    if(j != 0) left = curr[j-1];
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return curr[n-1];
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // return func1(m-1, n-1, dp);
        // return func2(m, n, dp);
        return func3(m, n);
    }
};