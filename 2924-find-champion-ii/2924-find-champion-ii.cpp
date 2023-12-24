class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        if (n == 1) return 0;
        vector<int> indegree(n);
        int ans = 0, already = 0;
        for (auto &edge : edges) indegree[edge[1]]++;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                if (already) return -1;
                else { ans = i; already++; }
            }
        }
        return ans;
    }
};