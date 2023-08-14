class DisjointSet
{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPr(int node)
    {
        if (node == parent[node])
            return node;
        else
            return parent[node] = findUPr(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int upar_u = findUPr(u);
        int upar_v = findUPr(v);
        if (upar_u == upar_v)
            return;
        if (rank[upar_u] < rank[upar_v])
            parent[upar_u] = upar_v;
        else if (rank[upar_u] > rank[upar_v])
            parent[upar_v] = upar_u;
        else
        {
            parent[upar_v] = upar_u;
            rank[upar_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int upar_u = findUPr(u);
        int upar_v = findUPr(v);
        if (upar_u == upar_v)
            return;
        if (size[upar_u] < size[upar_v])
        {
            parent[upar_u] = upar_v;
            size[upar_v] += size[upar_u];
        }
        else
        {
            parent[upar_v] = upar_u;
            size[upar_u] += size[upar_v];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(), row = 0, col = 0, nodeRow = 0, nodeCol = 0, cnt = 0;
        for(auto it: stones) {
            row = max(row, it[0]);
            col = max(col, it[1]);
        }
        DisjointSet ds(row + col + 1);
        for(auto it: stones) {
            nodeRow = it[0];
            nodeCol = it[1] + row + 1;
            ds.unionBySize(nodeRow, nodeCol);
        }
        for(int i = 0; i < row + col + 1; i++) {
            if(ds.parent[i] == i && ds.size[i] > 1) cnt++;
        }
        return n - cnt;
    }
};