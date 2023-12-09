class Solution {
private:
    bool dfs(int row, int col, int &org_color, int &color, vector<vector<bool>> &visited, vector<vector<int>> &grid, int &n, int &m) {

        if (row < 0 || col < 0 || row >= n || col >= m) return true;
        if (visited[row][col]) return false;
        if (grid[row][col] != org_color) return true;
        
        visited[row][col] = true;
        
        bool up = dfs(row - 1, col, org_color, color, visited, grid, n, m);
        bool right = dfs(row, col + 1, org_color, color, visited, grid, n, m);
        bool down = dfs(row + 1, col, org_color, color, visited, grid, n, m);
        bool left = dfs(row, col - 1, org_color, color, visited, grid, n, m);
        
        if (up || right || down || left) grid[row][col] = color;
        
        return false;
    }
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size(), m = grid[0].size();
        int org_color = grid[row][col];
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        dfs(row, col, org_color, color, visited, grid, n, m);
        return grid;
    }
};