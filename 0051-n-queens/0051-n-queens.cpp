class Solution {
private:
    bool positionSafe(int row, int col, vector<string> &board, int &n) {
        int nrow = row, ncol = col;
        
        // left-upper diagonal
        while (nrow >= 0 && ncol >= 0) {
            if(board[nrow][ncol] == 'Q') return false;
            nrow--;
            ncol--;
        }
        
        // left line
        nrow = row; ncol = col;
        while (ncol >= 0) {
            if(board[nrow][ncol] == 'Q') return false;
            ncol--;
        }
        
        // left-lower diagonal
        nrow = row; ncol = col;
        while (nrow < n && ncol >= 0) {
            if(board[nrow][ncol] == 'Q') return false;
            nrow++;
            ncol--;
        }
        return true;
    }
    void queen(int col, int &n, vector<string> &board, vector<vector<string>> &ans) {
        if(col == n) {
            ans.push_back(board);
            return;
        }
        for(int row = 0; row < n; row++) {
            if (positionSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                queen(col + 1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        // creating empty board with '.'
        for (int i = 0; i < n; i++) board[i] = s;
        queen(0, n, board, ans);
        return ans;
    }
};