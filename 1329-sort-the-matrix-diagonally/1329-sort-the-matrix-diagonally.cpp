class Solution {
private:
    void func(vector<vector<int>> &mat, int row, int col) {
        map<int, int> mp; // stores sorted values with their cnt
        int n = mat.size(), m = mat[0].size();
        for(int i = row, j = col; i < n && j < m; i++, j++) mp[mat[i][j]]++;
        int i = row, j = col;
        for(auto it: mp) {
            int val = it.first, cnt = it.second;
            for(int k = 0; k < cnt; k++, i++, j++) mat[i][j] = val;
        }
    }
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for(int i = 0; i < n; i++) func(mat, i, 0); // every row of 1st column
        for(int j = 0; j < m; j++) func(mat, 0, j); // every col of 1st row
        return mat;
    }
};