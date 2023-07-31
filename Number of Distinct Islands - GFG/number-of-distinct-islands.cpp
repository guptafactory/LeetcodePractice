//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int rowArr[4] = {0, 0, -1, 1};
    int colArr[4] = {-1, 1, 0, 0};
    void bfs(int baseRow, int baseCol, int &n, int &m, vector<vector<int>> &vis, vector<vector<int>>& grid, set <vector<pair<int, int>>> &sett)
    {
        vector <pair<int, int>> arr;
        queue <pair<int, int>> que;
        que.push({baseRow, baseCol});
        while(!que.empty())
        {
            int row = que.front().first, col = que.front().second;
            que.pop();
            arr.push_back({row - baseRow, col - baseCol});
            vis[row][col] = 1;
            for(int k = 0; k <= 3; k++)
            {
                int newRow = row + rowArr[k], newCol = col + colArr[k];
                if(newRow >=  0 && newRow < n && newCol >=  0 && newCol < m && !vis[newRow][newCol] && grid[newRow][newCol]) 
                {
                    vis[newRow][newCol] = 1;
                    que.push({newRow, newCol});
                }
            }
        }
        sett.insert(arr);
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), island = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set <vector<pair<int, int>>> sett;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j]) {
                    bfs(i, j, n, m, vis, grid, sett);
                }
            }
        }
        return sett.size();
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends