class Solution {
private:
    // up, right, down, left
    int delRow[4] = { -1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};
    void dfs(int row, int col, int &end_row, int &end_col, vector<vector<int>>& land, vector<vector<int>>& ans, int &n, int &m) {
        land[row][col] = 0;
        end_row = max(end_row, row);
        end_col = max(end_col, col);
        for (int k = 0; k < 4; k++) {
            int nrow = row + delRow[k], ncol = col + delCol[k];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && land[nrow][ncol]) dfs(nrow, ncol, end_row, end_col, land, ans, n, m);
        }
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int n = land.size(), m = land[0].size(), end_row = 0, end_col = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (land[i][j]) {
                    end_row = i;
                    end_col = j;
                    dfs(i, j, end_row, end_col, land, ans, n, m);
                    ans.push_back({i, j, end_row, end_col});
                }
            }
        }
        return ans;
    }
};