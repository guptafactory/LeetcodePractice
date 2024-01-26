class Solution {
public:
    int mod = 1e9+7;
    vector<vector<vector<int>>> dp;

    int solve(int n, int m, int maxMove, int startRow, int startColumn){
        if(startColumn < 0 || startColumn >= m || startRow < 0 || startRow >= n) return 1;
        if(maxMove == 0) return 0;
        if(dp[startRow][startColumn][maxMove] != -1) return dp[startRow][startColumn][maxMove];

        int up = solve(n, m, maxMove - 1, startRow - 1, startColumn);
        int down = solve(n, m, maxMove - 1, startRow + 1, startColumn);
        int left = solve(n, m, maxMove - 1, startRow, startColumn - 1);
        int right = solve(n, m, maxMove - 1, startRow, startColumn + 1);

        return dp[startRow][startColumn][maxMove] = ((up + down) % mod + (left + right) % mod) % mod;
    }

    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(maxMove + 1, -1)));
        return solve(n, m, maxMove, startRow, startColumn);
    }
};