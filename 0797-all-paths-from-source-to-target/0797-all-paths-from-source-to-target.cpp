class Solution {
private:
    vector<vector<int>> ans;
    void dfs(int node, int &n, vector<int> &arr, vector<vector<int>> &graph) {
        if(node == n-1) {
            ans.push_back(arr);
            return;
        }
        if(graph[node].size() == 0) return;
        for(int adjNode: graph[node]) {
            arr.push_back(adjNode);
            dfs(adjNode, n, arr, graph);
            arr.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> arr;
        arr.push_back(0);
        dfs(0, n, arr, graph);
        return ans;
    }
};