class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        vector<int> height(m, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) height[j] = 0;
                else height[j] += 1;
            }
            vector<int> order_height = height;
            sort(order_height.begin(), order_height.end());
            
            for(int j = 0; j < m; j++) {
                ans = max(ans, order_height[j] * (m-j));
            }
        }
        return ans;
    }
};