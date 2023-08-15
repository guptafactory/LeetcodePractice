class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        int cnt = 0, node = 0, adjNode = 0;
        unordered_map <int, bool> mp;
        vector<int> adj[n];
        vector<int> vis(n, 0);
        queue<int> que;
        for(vector<int> it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int x: restricted) mp[x] = true;
        que.push(0);
        while(!que.empty()) {
            node = que.front();
            que.pop();
            vis[node] = 1;
            cnt++;
            for(int adjNode: adj[node]) {
                if(!vis[adjNode] && mp.find(adjNode) == mp.end()) que.push(adjNode);
            }
        }
        return cnt;
    }
};