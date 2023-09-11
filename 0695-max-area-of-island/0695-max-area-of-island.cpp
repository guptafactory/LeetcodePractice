class Solution {
private:
    int delRow[4] = {0, -1, 0, 1};
    int delCol[4] = {-1, 0, 1, 0};
    int dfs(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>> &vis) {
        int cnt = 1;
        vis[i][j] = 1;
        for(int k = 0; k < 4; k++) {
            int row = i + delRow[k], col = j + delCol[k];
            if(row >= 0 && row < n && col >= 0 && col < m && grid[row][col] && !vis[row][col]) cnt += dfs(row, col, n, m, grid, vis);
        }
        return cnt;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] && !vis[i][j]) ans = max(ans, dfs(i, j, n, m, grid, vis));
            }
        }
        return ans;
    }
};