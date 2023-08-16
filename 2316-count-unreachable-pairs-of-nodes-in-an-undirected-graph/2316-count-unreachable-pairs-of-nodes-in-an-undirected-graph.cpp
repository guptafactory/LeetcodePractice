class Solution {
private:
    void dfs(int node, long long &cnt, vector<int> &vis, vector<int> adj[]) {
        vis[node] = 1;
        cnt++;
        for (int adjNode: adj[node]) {
            if (!vis[adjNode]) dfs(adjNode, cnt, vis, adj);
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long cnt = 0, ans = 0, rem = n;
        vector<int> adj[n], vis(n), components;
        for(vector<int> it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                // counting component size & mutiplying it with remaining elements & reducing the next remaining elements
                cnt = 0;
                dfs(i, cnt, vis, adj);
                ans += 1ll * (rem - cnt) * cnt;
                rem -= cnt;
            }
        }
        return ans;
    }
};