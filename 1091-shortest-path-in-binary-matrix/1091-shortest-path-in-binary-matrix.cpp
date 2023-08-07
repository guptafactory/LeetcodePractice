class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), dst = 0, i = 0, j = 0, row = 0, col = 0;
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        int delRow[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int delCol[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        queue<pair<int, pair<int, int>>> que;
        if(grid[0][0] == 0) { que.push({1, {0, 0}}); grid[0][0] = 1; }
        while(!que.empty()) {
            dst = que.front().first, row = que.front().second.first, col = que.front().second.second;
            que.pop();
            if(row == n-1 && col == n-1) return dst;
            for(int k = 0; k < 8; k++) {
                i = row + delRow[k], j = col + delCol[k];
                if(i >=0 && i < n && j >= 0 && j < n && grid[i][j] == 0 && dist[i][j] == INT_MAX) {
                    dist[i][j] = dst + 1;
                    que.push({dst + 1, {i, j}});
                }
            }
        }
        return -1;
    }
};