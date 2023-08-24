class Solution {
private:
    bool fillBoard(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                // checking for every empty cell
                if(board[i][j] == '.') {
                    // checking if any digit possible
                    for(char ch = '1'; ch <= '9'; ch++) {
                        // checking if taken digit is violating any rule
                        if(validNum(i, j, ch, board)) {
                            board[i][j] = ch;
                            if(fillBoard(board)) return true; // Sudoku is solved by child call
                            else board[i][j] = '.'; // wrong character
                        } 
                    }
                    return false; // no digit can be filled (last filled digit is wrong)
                } 
            }
        }
        return true;
    }
    bool validNum(int row, int col, char ch, vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            // checking vertically
            if(board[i][col] == ch) return false; //digit already present
            // checking horizontally
            if(board[row][i] == ch) return false; //digit already present
            // checking in box
            if(board[3 * (row/3) + i/3][3 * (col/3) + i%3] == ch) return false;
            
            // all rules checked & satisfied
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        fillBoard(board);
    }
};