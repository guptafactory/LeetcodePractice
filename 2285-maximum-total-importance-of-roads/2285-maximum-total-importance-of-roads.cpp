class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;
        vector<int> degree(n);
        // calculated degree of all nodes
        for(vector<int> it: roads) {
            degree[it[0]]++;
            degree[it[1]]++;
        }
        sort(degree.begin(), degree.end());
        // lower degree -> lower priority & lower node number
        for(int i = 0, priority = 1; i < n; i++, priority++) ans += 1ll * degree[i] * priority;
        return ans;
    }
};