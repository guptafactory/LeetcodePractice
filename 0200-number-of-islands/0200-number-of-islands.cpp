class Solution {
public:
    void bfs(int row, int col, int &n, int &m, vector<vector<int>> &vis, vector<vector<char>>& grid)
    {
        vis[row][col] = 1;
        queue <pair<int, int>> que;
        que.push({row, col});
        int rowArr[] = {0, 0, -1, 1};
        int colArr[] = {-1, 1, 0, 0};
        while(!que.empty())
        {
            row = que.front().first, col = que.front().second;
            que.pop();
            vis[row][col] = 1;
            for(int k = 0; k <= 3; k++)
            {
                int newRow = row + rowArr[k], newCol = col + colArr[k];
                if(newRow >=  0 && newRow < n && newCol >=  0 && newCol < m && !vis[newRow][newCol] && grid[newRow][newCol] == '1') 
                {
                    vis[newRow][newCol] = 1;
                    que.push({newRow, newCol});
                }
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), island = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vis[i][j] && grid[i][j] == '1') 
                {
                    island++;
                    bfs(i, j, n, m, vis, grid);
                }
            }
        }
        return island;
    }
};