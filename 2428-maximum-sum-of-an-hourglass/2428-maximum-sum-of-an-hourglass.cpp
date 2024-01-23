class Solution {
private:
    int hourglass_sum(int &i, int &j, vector<vector<int>>& grid) {
        return (grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1]) + grid[i][j] + (grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1]);
    }
public:
    int maxSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) ans = max(ans, hourglass_sum(i, j, grid));
        }
        return ans;
    }
};