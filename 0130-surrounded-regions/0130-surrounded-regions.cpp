class Solution {
public:
    int delRow[4] = {-1, 0, 0, 1};
    int delCol[4] = {0, -1, 1, 0};
    void dfs(int row, int col, int &n, int &m, vector<vector<int>> &vis, vector<vector<char>>& board)
    {
        vis[row][col] = 1;
        for(int k = 0; k < 4; k++) {
            int newRow = row + delRow[k], newCol = col + delCol[k];
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && board[newRow][newCol] == 'O' && !vis[newRow][newCol]) dfs(newRow, newCol, n, m, vis, board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int j = 0; j < m; j++) {
            // first row
            if(board[0][j] == 'O' && !vis[0][j]) dfs(0, j, n, m, vis, board);
            //last row
            if(board[n-1][j] == 'O' && !vis[n-1][j]) dfs(n-1, j, n, m, vis, board);
        }
        for(int i = 0; i < n; i++) {
            // first column
            if(board[i][0] == 'O' && !vis[i][0]) dfs(i, 0, n, m, vis, board);
            //last column
            if(board[i][m-1] == 'O' && !vis[i][m-1]) dfs(i, m-1, n, m, vis, board);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O' && !vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};