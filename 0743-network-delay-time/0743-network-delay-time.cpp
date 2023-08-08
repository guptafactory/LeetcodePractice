class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int dis = 0, node = 0, adjNode = 0, wt = 0, ans = 0;
        vector<pair<int, int>> adj[n+1];
        vector<int> dist(n+1, INT_MAX);
        for(auto it: times) adj[it[0]].push_back({it[1], it[2]});
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty()) {
            dis = pq.top().first;
            node = pq.top().second;
            pq.pop();
            for(auto it: adj[node]) {
                adjNode = it.first;
                wt = it.second;
                if(dis + wt < dist[adjNode]) {
                    dist[adjNode] = dis + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        // dist[0] = INT_MAX (as initialised)
        for(int i = 1; i < n+1; i++) ans = max(ans, dist[i]);
        return (ans == INT_MAX) ? -1 : ans;
    }
};