class Solution {
private:
    // top-down
    int func1(int i, int j, int &n, vector<vector<int>> &triangle, vector<vector<int>> &dp) {
        if(i == n-1) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = triangle[i][j] + func1(i+1, j, n, triangle, dp);
        int down_right = triangle[i][j] + func1(i+1, j+1, n, triangle, dp);
        
        return dp[i][j] = min(down, down_right);
    }
    // tabulation (bottom-up)
    int func2(vector<vector<int>>& triangle) {
        int ans = INT_MAX, n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e5));
        dp[0][0] = triangle[0][0];
        if(n == 1) return dp[0][0];
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i+1; j++) {
                dp[i][j] = min(dp[i][j], triangle[i][j] + dp[i-1][j]); // up
                if(j != 0) dp[i][j] = min(dp[i][j], triangle[i][j] + dp[i-1][j-1]); // up-left
                if(i == n-1) ans = min(ans, dp[i][j]);
            }
        }
        return ans;
    }
    // space optimisation
    // int func3(vector<vector<int>>& triangle) {
        // vector<int> prev, temp;
        // arr.push_back();
        // if(n == 1) return dp[0][0];
    // }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // return func1(0, 0, n, triangle, dp);
        return func2(triangle);
        // return func3(triangle);
    }
};