//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet
{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPr(int node)
    {
        if (node == parent[node])
            return node;
        else
            return parent[node] = findUPr(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int upar_u = findUPr(u);
        int upar_v = findUPr(v);
        if (upar_u == upar_v)
            return;
        if (rank[upar_u] < rank[upar_v])
            parent[upar_u] = upar_v;
        else if (rank[upar_u] > rank[upar_v])
            parent[upar_v] = upar_u;
        else
        {
            parent[upar_v] = upar_u;
            rank[upar_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int upar_u = findUPr(u);
        int upar_v = findUPr(v);
        if (upar_u == upar_v)
            return;
        if (size[upar_u] < size[upar_v])
        {
            parent[upar_u] = upar_v;
            size[upar_v] += size[upar_u];
        }
        else
        {
            parent[upar_v] = upar_u;
            size[upar_u] += size[upar_v];
        }
    }
};
class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size(), nrow = 0, ncol = 0, node_num = 0, adjNode_num = 0, sizeTotal = 0, ans = 0;
        int delRow[4] = {-1, 0, 0, 1};
        int delCol[4] = {0, -1, 1, 0};
        DisjointSet ds(n*n);
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                // Not a island
                if(grid[row][col] == 0) continue;
                for(int k = 0; k < 4; k++) {
                    nrow = row + delRow[k];
                    ncol = col + delCol[k];
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1) {
                        // creating components with their ultimate parents
                        node_num = row * n + col;
                        adjNode_num = nrow * n + ncol;
                        ds.unionBySize(node_num, adjNode_num);
                    }
                }
            }
        }
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                // Already a island
                if(grid[row][col] == 1) continue;
                set <int> components;
                for(int k = 0; k < 4; k++) {
                    nrow = row + delRow[k];
                    ncol = col + delCol[k];
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1) components.insert(ds.findUPr(nrow * n + ncol));
                }
                sizeTotal = 1;
                for(auto it: components) sizeTotal += ds.size[it];
                ans = max(ans, sizeTotal);
            }
        }
        // if all 1s in matrix
        if(ds.size[0] == n*n) return n*n;
        else return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends