class Solution {
public:
    void dfs(vector<int> adjList[], vector<int> &vis, int node)
    {
        vis[node] = 1;
        for (auto it : adjList[node])
        {
            if (!vis[it])
                dfs(adjList, vis, it);
        }
    }
    void AdjList(int n, vector<vector<int>>& isConnected, vector<int> adjList[])
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(isConnected[i][j])
                {
                    adjList[i+1].push_back(j+1);
                    adjList[j+1].push_back(i+1);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), province = 0;
        vector<int> adjList[n + 1];
        AdjList(n, isConnected, adjList);
        vector <int> vis(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                province++;
                dfs(adjList, vis, i);
            }
        }
        return province;
    }
};