class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        queue <pair<int, pair<int, int>>> que;
        vector<int> dist(n, INT_MAX);
        int stops = 0, city = 0, dis = 0, newCity = 0, newDis = 0;
        for(auto it: flights) adj[it[0]].push_back({it[1], it[2]});
        // Stop, Source, past_dist
        que.push({0, {src, 0}});
        dist[src] = 0;
        while(!que.empty()) {
            stops = que.front().first, city = que.front().second.first, dis = que.front().second.second;
            que.pop();
            if(stops > k) break;
            for(auto it: adj[city]) {
                newCity = it.first, newDis = it.second;
                if(dis + newDis < dist[newCity] && stops <= k) {
                    dist[newCity] = dis + newDis;
                    que.push({ stops+1, {newCity, dist[newCity]} });
                }
            }
        }
        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};