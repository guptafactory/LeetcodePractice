class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPr(int node) {
        if (node == parent[node])
            return node;
        else
            return parent[node] = findUPr(parent[node]);
    }
    void unionByRank(int u, int v) {
        int upar_u = findUPr(u);
        int upar_v = findUPr(v);
        if (upar_u == upar_v)
            return;
        if (rank[upar_u] < rank[upar_v])
            parent[upar_u] = upar_v;
        else if (rank[upar_u] > rank[upar_v])
            parent[upar_v] = upar_u;
        else {
            parent[upar_v] = upar_u;
            rank[upar_u]++;
        }
    }
    void unionBySize(int u, int v) {
        int upar_u = findUPr(u);
        int upar_v = findUPr(v);
        if (upar_u == upar_v)
            return;
        if (size[upar_u] < size[upar_v]) {
            parent[upar_u] = upar_v;
            size[upar_v] += size[upar_u];
        }
        else {
            parent[upar_v] = upar_u;
            size[upar_u] += size[upar_v];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map <string, int> mapMailNode;
        vector<string> mergedMail[n];
        vector<vector<string>> ans;
        
        for (int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if(mapMailNode.find(email) == mapMailNode.end()) mapMailNode[email] = i;
                else ds.unionBySize(i, mapMailNode[email]);
            }
        }
        
        for(auto it: mapMailNode) {
            string email = it.first;
            int node = ds.findUPr(it.second);
            mergedMail[node].push_back(email);
        }
        
        for(int i = 0; i < n; i++) {
            if(mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(string str: mergedMail[i]) temp.push_back(str);
            ans.push_back(temp);
        }
        return ans;
    }
};