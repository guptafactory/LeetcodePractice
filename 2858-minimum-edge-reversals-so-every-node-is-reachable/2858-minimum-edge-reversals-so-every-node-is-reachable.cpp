class Solution {
private:
    int cntReversals(int node, vector<vector<int>> &tree, vector<vector<int>> &revtree, vector<int> &reversals, vector<int> &vis) {
        vis[node] = 1;
        int val = 0;
        for(int adjNode: tree[node]) {
            if(!vis[adjNode]) val += cntReversals(adjNode, tree, revtree, reversals, vis);
        }
        for(int adjNode: revtree[node]) {
            if(!vis[adjNode]) val += 1 + cntReversals(adjNode, tree, revtree, reversals, vis);
        }
        return reversals[node] = val;
    }
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<int> ans(n), reversals(n), vis(n);
        vector<vector<int>> tree(n), revtree(n);
        
        for(int i = 0; i < edges.size(); i++) {
            tree[edges[i][0]].push_back(edges[i][1]);
            revtree[edges[i][1]].push_back(edges[i][0]);
        }
        
        int val = cntReversals(0, tree, revtree, reversals, vis);
        vis.clear();
        vis.resize(n);
        
        queue<pair<int, int>> que;
        que.push({0, 0});
        
        while(!que.empty()) {
            int node = que.front().first, rev = que.front().second;
            que.pop();
            vis[node] = 1;
            
            int cval = rev + reversals[node];
            ans[node] = cval;
            
            for(int adjNode: tree[node]) {
                if(!vis[adjNode]) que.push({adjNode, ans[node] - reversals[adjNode] + 1});
            }
            for(int adjNode: revtree[node]) {
                if(!vis[adjNode]) que.push({adjNode, ans[node] - reversals[adjNode] - 1});
            }
        }
        return ans;
    }
};