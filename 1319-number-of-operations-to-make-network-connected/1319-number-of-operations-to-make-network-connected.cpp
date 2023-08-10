class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<int> adj[]) {
        vis[node] = 1;
        for(int adjNode: adj[node]) {
            if(!vis[adjNode]) dfs(adjNode, vis, adj);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        vector<int> vis(n, 0);
        int edges = connections.size(), component = 0;
        for(vector<int> it: connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i = 0; i < n; i++) {
            if(!vis[i]) { dfs(i, vis, adj); component++; }
        }
        return (edges < n - 1) ? -1 : component-1;
    }
};