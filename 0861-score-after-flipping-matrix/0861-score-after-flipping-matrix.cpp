class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), one = 0, flips = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1) continue;
            flips++;
            for (int j = 0; j < m; j++) grid[i][j] = !grid[i][j];
        }
        for (int j = 0; j < m; j++) {
            one = 0;
            for (int i = 0; i < n; i++) {
                if (grid[i][j]) one++;
            }
            if (one < (n + 1) / 2) {
                flips++;
                one = n - one;
            }
            sum += 1ll * one * (1ll << (m - j - 1));
        }
        return sum;
    }
};