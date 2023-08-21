class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int row = board.size(), col = board[0].size(), cnt = 0;
        // check any one corner (top-right, top-left, bottom-right, bottom-left) for whole matrix
        // Corner selected will also affect the direction of matrix traversal
        // if '.' is present, then it is a new Battleship, else previous one
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'X' && (i == 0 || board[i-1][j] == '.') && (j == 0 || board[i][j-1] == '.'))
                    cnt++;
            }
        }
        return cnt;
    }
};