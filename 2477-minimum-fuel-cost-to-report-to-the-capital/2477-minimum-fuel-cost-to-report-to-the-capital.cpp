class Solution {
public:
    long long fuel = 0;
    long long dfs(int node, int &seats, vector<int> &vis, vector<int> adj[]) {
        vis[node] = 1;
        long long ppl = 1;
        for(int adjNode: adj[node]) {
            if(!vis[adjNode]) ppl += dfs(adjNode, seats, vis, adj);
        }
        long long car = ppl/seats;
        if(ppl%seats) car++;
        if(node != 0) fuel += car;
        return ppl;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<int> adj[n+1];
        vector<int> vis(n+1, 0);
        for(vector<int> it: roads) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0, seats, vis, adj);
        return fuel;
    }
};