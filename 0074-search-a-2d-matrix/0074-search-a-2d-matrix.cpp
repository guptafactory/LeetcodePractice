class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size(), row = 0, col = 0, low = 0, mid = 0, high = n - 1;
        if (target < matrix[0][0] || target > matrix[n - 1][m - 1]) return false;
        // finding row
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] > target) high = mid - 1;
            else { row = mid; low = mid + 1; }
        }
        low = 0;
        high = m - 1;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};