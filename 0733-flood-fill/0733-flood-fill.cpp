class Solution {
private:
    int delRow[4] = { -1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};
    void dfs(int row, int col, vector<vector<int>>& image, int &n, int &m, int &org_color, int &color) {
        image[row][col] = color;
        for (int k = 0; k < 4; k++) {
            int nrow = row + delRow[k], ncol = col + delCol[k];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == org_color) dfs(nrow, ncol, image, n, m, org_color, color);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size(), org_color = image[sr][sc];
        if (org_color == color) return image;
        dfs(sr, sc, image, n, m, org_color, color);
        return image;
    }
};