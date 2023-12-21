class Solution {
private:
    int delRow[4] = { -1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};
    void removeBoundary(int &row, int &col, vector<vector<int>>& grid, int &n, int &m) {
        grid[row][col] = -1;
        for (int k = 0; k < 4; k++) {
            int nrow = row + delRow[k], ncol = col + delCol[k];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0) removeBoundary(nrow, ncol, grid, n, m);
        }
    }
    void iterateBoundary(vector<vector<int>>& grid, int &n, int &m) {
        // iterate 1st row
        for (int i = 0, j = 0; j < m; j++) {
            if (grid[i][j] == 0) removeBoundary(i, j, grid, n, m);
        }
        // iterate last row
        for (int i = n - 1, j = 0; j < m; j++) {
            if (grid[i][j] == 0) removeBoundary(i, j, grid, n, m);
        }
        // iterate 1st col
        for (int i = 0, j = 0; i < n; i++) {
            if (grid[i][j] == 0) removeBoundary(i, j, grid, n, m);
        }
        // iterate last col
        for (int i = 0, j = m - 1; i < n; i++) {
            if (grid[i][j] == 0) removeBoundary(i, j, grid, n, m);
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        iterateBoundary(grid, n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) { ans++; removeBoundary(i, j, grid, n, m); }
            }
        }
        return ans;
    }
};