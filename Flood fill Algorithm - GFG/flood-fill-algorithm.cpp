//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row, col, nrow, ncol, n = image.size(), m = image[0].size(), color = image[sr][sc];
        if(color == newColor) return image;
        int delRow[4] = {-1, 0, 0, 1};
        int delCol[4] = {0, 1, -1, 0};
        vector<vector<int>> matrix = image;
        queue<pair<int, int>> que;
        que.push({sr, sc});
        matrix[sr][sc] = newColor;
        while(!que.empty()) {
            row = que.front().first; 
            col = que.front().second;
            que.pop();
            for(int k = 0; k < 4; k++) {
                nrow = row + delRow[k]; 
                ncol = col + delCol[k];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && matrix[nrow][ncol] == color) {
                    matrix[nrow][ncol] = newColor;
                    que.push({nrow, ncol});
                }
            }
        }
        return matrix;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends