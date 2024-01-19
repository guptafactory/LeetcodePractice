class Solution {
private:
    int delCol[3] = { -1, 0, 1};
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col < n; col++) {
                int val = INT_MAX;
                for (int k = 0; k < 3; k++) {
                    int nrow = row + 1, ncol = col + delCol[k];
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n) val = min(val, matrix[nrow][ncol]);
                }
                matrix[row][col] += val;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cout << matrix[i][j] << ' ';
            cout << endl;
        }
        int ans = INT_MAX;
        for(int j = 0; j < n; j++) ans = min(ans, matrix[0][j]);
        return ans;
        // return *min(matrix[0].begin(), matrix[0].end());
    }
};