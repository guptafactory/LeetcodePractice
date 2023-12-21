class Solution {
private:
    int delRow[4] = { -1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};
    void dfs(int row, int col, vector<vector<int>>& grid1, vector<vector<int>>& grid2, int &n, int &m, bool &flag) {
        if (grid1[row][col] == 0) flag = 0;
        grid2[row][col] = 0;
        for (int k = 0; k < 4; k++) {
            int nrow = row + delRow[k], ncol = col + delCol[k];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid2[nrow][ncol] == 1) dfs(nrow, ncol, grid1, grid2, n, m, flag);
        }
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size(), ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 0) continue;
                bool flag = true;
                dfs(i, j, grid1, grid2, n, m, flag);
                if (flag) ans++;
            }
        }
        return ans;
    }
};