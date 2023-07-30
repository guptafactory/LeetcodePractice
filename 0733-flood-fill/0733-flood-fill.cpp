class Solution {
public:
    int rowArr[4] = {0, 0, -1, 1};
    int colArr[4] = {-1, 1, 0, 0};
    void dfs(int sr, int sc, int &color, int &prevColor, int &n, int &m, vector<vector<int>>& ans)
    {
        ans[sr][sc] = color;
        for(int k = 0; k <= 3; k++)
        {
            int newRow = sr + rowArr[k], newCol = sc + colArr[k];
            if(newRow >=  0 && newRow < n && newCol >=  0 && newCol < m && ans[newRow][newCol] == prevColor) dfs(newRow, newCol, color, prevColor, n, m, ans);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int prevColor = ans[sr][sc], n = image.size(), m = image[0].size();
        if(prevColor != color) dfs(sr, sc, color, prevColor, n, m, ans);
        return ans;
    }
};