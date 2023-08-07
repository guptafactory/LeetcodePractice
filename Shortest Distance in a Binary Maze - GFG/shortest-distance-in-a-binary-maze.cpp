//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        if(source == destination) return 0;
        int n = grid.size(), m = grid[0].size(), dst = 0, i = 0, j = 0, row = 0, col = 0;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        int delRow[4] = {-1, 0, 0, 1};
        int delCol[4] = {0, -1, 1, 0};
        queue<pair<int, pair<int, int>>> que;
        que.push({0, source});
        while(!que.empty()) {
            dst = que.front().first, row = que.front().second.first, col = que.front().second.second;
            que.pop();
            for(int k = 0; k < 4; k++) {
                i = row + delRow[k], j = col + delCol[k];
                if(i >=0 && i < n && j >= 0 && j < m && grid[i][j] == 1 && dist[i][j] == INT_MAX) {
                    dist[i][j] = dst + 1;
                    if(i == destination.first && j == destination.second) return dist[i][j];
                    que.push({dst + 1, {i, j}});
                }
            }
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends