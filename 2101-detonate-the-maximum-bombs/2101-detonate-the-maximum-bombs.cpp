class Solution {
private:
    void dfs(int node, long long &cnt, vector<int> &vis, vector<int> adj[]) {
        vis[node] = 1;
        cnt++;
        for(int adjNode: adj[node]) {
            if(!vis[adjNode]) dfs(adjNode, cnt, vis, adj);
        }
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        long long n = bombs.size(), Ux, Uy, Urad, Vx, Vy, Vrad, distX, distY, cnt, ans = 0;
        vector<int> adj[n];
        // T.C. -> O(n ^ 2)
        // connecting nodes of graph (closely distanced bombs)
        for(int i = 0; i < n; i++) {
            Ux = bombs[i][0]; Uy = bombs[i][1]; Urad = bombs[i][2];
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                Vx = bombs[j][0]; Vy = bombs[j][1]; Vrad = bombs[j][2];
                distX = abs(Ux - Vx);
                distY = abs(Uy - Vy);
                if(Urad * Urad >= (distX * distX) + (distY * distY)) adj[i].push_back(j);
            }
        }
        // calculating connected nodes/bombs for every node
        // For every node/bomb, new visited array is created to check connected bomb for that bomb as any node might be connected to multiple nodes
        for(int i = 0; i < n; i++) {
            cnt = 0;
            vector<int> vis(n);
            dfs(i, cnt, vis, adj);
            ans = max(ans, cnt);
        }
        return ans;
    }
};