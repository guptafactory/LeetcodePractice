class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), t = 0;
        vector<vector<int>> arr = grid;
        // stores {{row, col}, time}
        queue <pair<int, int>> que;
        int delRow[] = {0, 0, -1, 1};
        int delCol[] = {-1, 1, 0, 0};
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(arr[i][j] == 2) que.push({i, j}); // Rotten oranges stores at t = 0
            }
        }
        while(!que.empty())
        {
            int cnt = que.size();
            while(cnt--)
            {
                auto pr = que.front();
                que.pop();
                int row = pr.first, col = pr.second;
                for(int k = 0; k <= 3; k++)
                {
                    int newRow = row + delRow[k], newCol = col + delCol[k];
                    if(newRow >=  0 && newRow < n && newCol >=  0 && newCol < m && arr[newRow][newCol] == 1) {
                        arr[newRow][newCol] = 2;
                        que.push({newRow, newCol});
                    }
                }
            }
            t++;
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(arr[i][j] == 1) return -1;
            }
        }
        return t-1 > 0 ? t-1 : 0;
    }
};