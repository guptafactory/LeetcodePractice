class Solution {
public:
    void dfs(int node, int &cntNodes, int &cntEdges, vector<int> &vis, vector<int> adj[]) {
        vis[node] = 1;
        cntNodes++;
        for(int adjNode: adj[node]) {
            if(!vis[adjNode]) { dfs(adjNode, cntNodes, cntEdges, vis, adj); }
            cntEdges++; 
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0, cntNodes = 0, cntEdges = 0;
        vector<int> adj[n];
        vector<int> vis(n, 0);
        for(vector<int> it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                cntNodes = 0;
                cntEdges = 0;
                dfs(i, cntNodes, cntEdges, vis, adj);
                if(cntEdges/2 == cntNodes*(cntNodes - 1)/2) ans++;
            }
        }
        return ans;
    }
};