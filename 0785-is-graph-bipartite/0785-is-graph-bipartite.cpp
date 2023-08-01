class Solution {
public:
    bool componentBipartite(int start, vector<int> &color, vector<vector<int>>& graph) {
        queue<int> que;
        que.push(start);
        color[start] = 0;
        while(!que.empty()) {
            int node = que.front();
            que.pop();
            for(int adjNode: graph[node]) {
                if(color[adjNode] == -1) {
                    color[adjNode] = !color[node];
                    que.push(adjNode);
                }
                else if(color[adjNode] == color[node]) return false;   
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
              if(componentBipartite(i, color, graph) == false) return false;
            } 
        }
        return true;
    }
};