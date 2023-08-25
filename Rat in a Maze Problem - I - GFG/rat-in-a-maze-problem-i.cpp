//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    vector<string> ans;
    // {Down, Left, Right, Up}
    vector<int> delRow = {1, 0, 0, -1};
    vector<int> delCol = {0, -1, 1, 0};
    string move = "DLRU";
    void check(int row, int col, string &str, int &n, vector<vector<int>> &m) {
        if(row == n-1 && col == n-1) {
            if(m[row][col] == 1) ans.push_back(str);
            return;
        }
        m[row][col] = 0;
        for(int k = 0; k < 4; k++) {
            int nrow = row + delRow[k];
            int ncol = col + delCol[k];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && m[nrow][ncol] == 1) {
                str.push_back(move[k]);
                check(nrow, ncol, str, n, m);
                str.pop_back();
            }
        }
        m[row][col] = 1;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0] == 0) return ans;
        string str;
        check(0, 0, str, n, m);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends