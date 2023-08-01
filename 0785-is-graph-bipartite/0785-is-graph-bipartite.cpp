class Solution {
public:
    bool componentBipartite(int node, int presentColor, vector<int> &color, vector<vector<int>>& graph) {
        color[node] = presentColor;
        for(int adjNode: graph[node]) {
                if(color[adjNode] == -1) {
                    if(componentBipartite(adjNode, !color[node], color, graph) == false) return false;
                }
                else if(color[adjNode] == color[node]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
              if(componentBipartite(i, 0, color, graph) == false) return false;
            } 
        }
        return true;
    }
};