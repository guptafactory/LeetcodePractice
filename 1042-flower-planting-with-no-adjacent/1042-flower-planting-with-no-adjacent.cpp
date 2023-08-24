class Solution {
private:
    bool isSafe(int node, vector<int> adj[], vector<int> &color, int clr) {
        for(int adjNode: adj[node]) {
            if(color[adjNode] == clr) return false;
        }
        return true;
    }
    bool solve(int node, vector<int> adj[], vector<int> &color, int &n) {
        if(node == n) return true; // if all nodes can be colored
        for(int clr = 1; clr <= 4; clr++) {
            // checking all safe colors on given node
            if(isSafe(node, adj, color, clr)) {
                color[node] = clr;
                if(solve(node + 1, adj, color, n)) return true;
                color[node] = 0;
            }
        }
        return false;
    }
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> adj[n];
        vector<int> color(n, 0);
        for(vector<int> it: paths) {
            adj[it[0]-1].push_back(it[1]-1);
            adj[it[1]-1].push_back(it[0]-1);
        }
        solve(0, adj, color, n);
        return color;
    }
};