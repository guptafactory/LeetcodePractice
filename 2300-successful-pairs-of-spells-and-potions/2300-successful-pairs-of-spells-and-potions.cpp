class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size(), m = potions.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            long long val = ceil(success / (double)spells[i]);
            int cnt = m - (lower_bound(potions.begin(), potions.end(), val) - potions.begin());
            ans[i] = cnt;
        }
        return ans;
    }
};