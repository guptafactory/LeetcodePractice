class Solution {
private:
    void dfs(int ind, int &n, vector<vector<int>>& isConnected, vector<bool> &vis) {
        vis[ind] = true;
        for (int j = 0; j < n; j++) {
            if (isConnected[ind][j] && !vis[j]) dfs(j, n, isConnected, vis);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ans = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans++;
                dfs(i, n, isConnected, vis);
            }
        }
        return ans;
    }
};