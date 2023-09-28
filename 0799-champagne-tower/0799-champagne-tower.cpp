class Solution {
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
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(100, vector<double>(100, -1.0));
        return min(func(query_row, query_glass, poured, dp), 1.0);
    }
};