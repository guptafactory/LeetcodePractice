class Solution {
private:
    int time = 1;
    void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, vector<int> &insertTime, vector<int> &lowestTime, vector<vector<int>> &bridges) {
        vis[node] = 1;
        insertTime[node] = lowestTime[node] = time++;
        for(int adjNode: adj[node]) {
            if(adjNode == parent) continue;
            if(!vis[adjNode]) {
                dfs(adjNode, node, adj, vis, insertTime, lowestTime, bridges);
                // Backtracking to the parent
                lowestTime[node] = min(lowestTime[node], lowestTime[adjNode]);
                // Check for bridge
                if(insertTime[node] < lowestTime[adjNode]) {
                    bridges.push_back({node, adjNode});
                }
            } else {
                lowestTime[node] = min(lowestTime[node], lowestTime[adjNode]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        vector<int> vis(n, 0), insertTime(n), lowestTime(n);
        vector<vector<int>> bridges;
        for(vector<int> it: connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0, -1, adj, vis, insertTime, lowestTime, bridges);
        return bridges;
    }
};