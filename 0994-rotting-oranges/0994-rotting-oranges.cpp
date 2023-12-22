class Solution {
private:
    int delRow[4] = { -1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), time = 0;
        queue<pair<int, int>> que;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) que.push({i, j});
            }
        }
        while (!que.empty()) {
            int cnt = que.size(), more_oranges = 0;
            // All fresh oranges directly connected are marked rotten & pushed to queue for next degree of iteration
            while (cnt--) {
                auto pr = que.front();
                que.pop();
                int row = pr.first, col = pr.second;
                for (int k = 0; k < 4; k++) {
                    int nrow = row + delRow[k], ncol = col + delCol[k];
                    if (nrow >= 0 && nrow < n && ncol >= 0 & ncol < m && grid[nrow][ncol] == 1) {
                        more_oranges = 1;
                        grid[nrow][ncol] = 2;
                        que.push({nrow, ncol});
                    }
                }
            }
            if (more_oranges) time++;
        }
        for (auto arr : grid) {
            for (auto x : arr) { if (x == 1) return -1; }
        }
        return time;
    }
};