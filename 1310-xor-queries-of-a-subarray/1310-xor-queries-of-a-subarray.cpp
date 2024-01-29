class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size(), l = 0, r = 0, q = queries.size();
        vector<int> ans(q);
        for (int i = 1; i < n; i++) arr[i] ^= arr[i - 1];
        for (int k = 0; k < q; k++) {
            l = queries[k][0];
            r = queries[k][1];
            if (l == 0) ans[k] = arr[r];
            else ans[k] = arr[l - 1] ^ arr[r];
        }
        return ans;
    }
};