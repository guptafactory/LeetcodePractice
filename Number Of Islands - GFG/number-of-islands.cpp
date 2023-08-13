//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet
{
    vector<int> rank, parent, size;

public:
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        int k = operators.size(), row = 0, col = 0, nrow = 0, ncol = 0, prev_ans = 0, node_num = 0, adjNode_num = 0;
        vector<int> ans;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delRow[4] = {-1, 0, 0, 1};
        int delCol[4] = {0, -1, 1, 0};
        DisjointSet ds(n*m);
        for (auto it: operators) {
            row = it[0]; col = it[1];
            if(vis[row][col] == 1) { 
                // edge repeating
                ans.push_back(prev_ans); 
                continue;
            }
            vis[row][col] = 1;
            prev_ans++;
            for(int k = 0; k < 4; k++) {
                nrow = row + delRow[k];
                ncol = col + delCol[k];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 1) {
                    node_num = row * m + col;
                    adjNode_num = nrow * m + ncol;
                    if(ds.findUPr(node_num) != ds.findUPr(adjNode_num)) {
                        // if parent different, then reduce component by combining both
                        prev_ans--;
                        ds.unionBySize(node_num, adjNode_num);
                    }
                    // if parent same, component already reduced previously
                }
            }
            ans.push_back(prev_ans);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends