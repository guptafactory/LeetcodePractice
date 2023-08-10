class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 1), ans;
        for(vector<int> it: edges) vis[it[1]] = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 1) ans.push_back(i);
        }
        return ans;
    }
};