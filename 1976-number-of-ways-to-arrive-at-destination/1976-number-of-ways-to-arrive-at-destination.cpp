
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long dis = 0, node = 0, adjNode = 0, wt = 0, mod = 1e9 + 7;
        vector <pair<long long, long long>> adj[n];
        vector <long long> ways(n, 0), dist(n, LLONG_MAX);
        priority_queue <pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        for(auto it: roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        ways[0] = 1;
        dist[0] = 0;
        pq.push({0, 0});
        while(!pq.empty()) {
            dis = pq.top().first;
            node = pq.top().second;
            pq.pop();
            for(auto it: adj[node]) {
                adjNode = it.first; 
                wt = it.second;
                if(dis + wt < dist[adjNode]) {
                    ways[adjNode] = ways[node];
                    dist[adjNode] = dis + wt;
                    pq.push({dist[adjNode], adjNode});
                } else if(dis + wt == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node])%mod;
                }
            }
        }
        return ways[n-1];
    }
};