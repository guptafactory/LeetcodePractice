class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<pair<int, int>> adj[V];
        for(int i = 0; i < V; i++) {
            for(int j = i + 1; j < V; j++) {
                adj[i].push_back({j, abs(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]))});
                adj[j].push_back({i, abs(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]))});
            }
        }
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        vector<int> vis(V, 0);
        pq.push({0, 0});
        int sum  = 0, node = 0, wt = 0, adjNode = 0, edgeWt = 0;
        while(!pq.empty()) {
            node = pq.top().second;
            wt = pq.top().first;
            pq.pop();
            if(vis[node] == 1) continue;
            vis[node] = 1;
            sum += wt;
            for(auto it: adj[node]) {
                adjNode = it.first;
                edgeWt = it.second;
                if(vis[adjNode] == 0) pq.push({edgeWt, adjNode});
            }
        }
        return sum;
    }
};