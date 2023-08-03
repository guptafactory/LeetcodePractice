class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adjRev(V);
        vector<int> indegree(V, 0), ans;
        queue<int> que;
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < graph[i].size(); j++) {
                adjRev[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) que.push(i);
        }
        while(!que.empty()) {
            int node = que.front();
            que.pop();
            ans.push_back(node);
            for(int adjNode: adjRev[node]) {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) que.push(adjNode);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};