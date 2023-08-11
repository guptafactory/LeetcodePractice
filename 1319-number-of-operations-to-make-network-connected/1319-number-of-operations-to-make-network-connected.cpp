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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size(), component = 0;
        DisjointSet ds(n);
        for(vector<int> it: connections) ds.unionByRank(it[0], it[1]);
        for(int i = 0; i < n; i++) {
            if (ds.findUPr(i) == i) component++;
        }
        return (edges < n - 1) ? -1 : component-1;
    }
};