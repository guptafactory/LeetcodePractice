class Solution {
public:
    bool dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<int> &check, vector<vector<int>>& graph) {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        for(int adjNode: graph[node]) {
            if(!vis[adjNode] && dfs(adjNode, vis, pathVis, check, graph) == true) { check[node] = 0; return true; }
            else if(pathVis[adjNode] == 1) { check[node] = 0; return true; }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, 0), pathVis(V, 0), check(V, 0), ans;
        for(int i = 0; i < V; i++) {
            if(!vis[i]) dfs(i, vis, pathVis, check, graph);
        }
        for(int i = 0; i < V; i++) {
            if(check[i] == 1) ans.push_back(i);
        }
        return ans;
    }
};