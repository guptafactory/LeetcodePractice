//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size(), m = grid[0].size();
	    vector<vector<int>> vis(n, vector<int>(m, 0));
	    vector<vector<int>> dist(n, vector<int>(m, 0));
	    queue <pair<pair<int, int>, int>> que;
	    int delRow[4] = {-1, 0, 0, 1 };
	    int delCol[4] = {0, -1, 1, 0};
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < m; j++) {
	            if(grid[i][j] == 1) { 
	                que.push({{i, j}, 0});
	                vis[i][j] = 1;
	            }
	            else vis[i][j] = 0;
	        }
	    }
	    while(!que.empty()) {
	        int row = que.front().first.first, col = que.front().first.second, steps = que.front().second;
	        dist[row][col] = steps;
	        que.pop();
	        for(int k = 0; k < 4; k++)
	        {
	            int newRow = row + delRow[k], newCol = col + delCol[k];
	            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !vis[newRow][newCol]) {
	                vis[newRow][newCol] = 1;
	                que.push({{newRow, newCol}, steps + 1});
	            }
	        }
	    }
	    return dist;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends