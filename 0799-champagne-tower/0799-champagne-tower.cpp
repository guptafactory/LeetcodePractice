class Solution {
private:
    // top-down
    double func(int i, int j, int &poured, vector<vector<double>> &dp) {
        if(i < 0 || j < 0 || j > i) return 0.0;
        if(i == 0 && j == 0) return poured;

        if(dp[i][j] != -1.0) return dp[i][j];
        double up_left = func(i-1, j-1, poured, dp);
        double up = func(i-1, j, poured, dp);
        double ans = (up_left > 1) ? (up_left - 1.0)/2.0 : 0.0;
        ans += (up > 1.0) ? (up - 1)/2.0 : 0.0;
        return dp[i][j] = ans;
    } 
    // bottom-up
    double func2(int row, int col, int &poured) {
        vector<vector<double>> dp(100, vector<double>(100, 0.0));
        dp[0][0] = (double)poured;
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j <= i; j++) {
                double val = max((dp[i][j] - 1.0)/2.0, 0.0);
                dp[i+1][j] += val; // down
                dp[i+1][j+1] += val; // down-right
            }
        }
        
        return min(dp[row][col], 1.0);
    } 
    // space-optimisation
    double func3(int row, int col, int &poured) {
        vector<double> prev(100, 0.0);
        prev[0] = poured;
        
        for(int i = 0; i < row; i++) {
            vector<double> curr(100, 0.0);
            for(int j = 0; j <= i; j++) {
                double val = max((prev[j] - 1.0)/2.0, 0.0);
                curr[j] += val; // down
                curr[j+1] += val; // down-right
            }
            prev = curr;
        }
        return min(prev[col], 1.0);
    }
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // vector<vector<double>> dp(100, vector<double>(100, -1.0));
        // return min(func(query_row, query_glass, poured, dp), 1.0);
        // return func2(query_row, query_glass, poured);
        return func3(query_row, query_glass, poured);
    }
};