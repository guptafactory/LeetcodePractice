class Solution {
    int lessEqual(int &val, int &n, vector<vector<int>>& matrix) {
        int cnt = 0, i = 0, j = n - 1;
        while (j >= 0 && i < n) {
            if (matrix[i][j] > val) j--;
            else {
                cnt += j + 1;
                i++;
            }
        }
        return cnt;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), low = 0, mid = 0, high = 0, cnt = 0;
        low = matrix[0][0];
        high = matrix[n - 1][n - 1];
        while (low < high) {
            mid = low + (high - low) / 2;
            cnt = lessEqual(mid, n, matrix);
            // cout << mid << ' ' << cnt << endl;
            // if (cnt == k) return mid;
            if (cnt < k) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};