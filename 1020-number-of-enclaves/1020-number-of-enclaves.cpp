class Solution {
    vector<vector<int>> dir = {{ -1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void dfs(int row, int col, vector<vector<int>>& grid, int &n, int &m) {
        grid[row][col] = 0;
        for (int k = 0; k < 4; k++) {
            int nrow = row + dir[k][0], ncol = col + dir[k][1];
            if (nrow < 0 || ncol < 0 || nrow >= n || ncol >= m || grid[nrow][ncol] == 0) continue;
            dfs(nrow, ncol, grid, n, m);
        }
    }
    void callDFS(vector<vector<int>>& grid, int &n, int &m) {
        for (int i = 0, j = 0; i < n; i++) { if (grid[i][j]) dfs(i, j, grid, n, m); } // 1st colm
        for (int i = 0, j = 0; j < m; j++) { if (grid[i][j]) dfs(i, j, grid, n, m); } // 1st row
        for (int i = 0, j = m - 1; i < n; i++) { if (grid[i][j]) dfs(i, j, grid, n, m); } // last colm
        for (int i = n - 1, j = 0; j < m; j++) { if (grid[i][j]) dfs(i, j, grid, n, m); } // last row
    }
    int cnt(vector<vector<int>>& grid, int &n, int &m) {
        int ans = 0;
        for (int i = 1; i < n-1; i++) {
            for (int j = 1; j < m-1; j++) {
                if (grid[i][j]) ans++;
            }
        }
        return ans;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        callDFS(grid, n, m);
        return cnt(grid, n, m);
    }
};