class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long topSum = accumulate(begin(grid[0]), end(grid[0]), 0ll), bottomSum = 0, ans = LLONG_MAX;
        for(int i = 0; i < grid[0].size(); i++) {
            topSum -= grid[0][i];
            ans = min(ans, max(topSum, bottomSum));
            bottomSum += grid[1][i]; // updating bottom sum at last time of index switching
        }
        return ans;
    }
};