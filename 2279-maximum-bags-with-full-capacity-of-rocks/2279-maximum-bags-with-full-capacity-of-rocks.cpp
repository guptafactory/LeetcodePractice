class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<long long> add_more;
        int n = capacity.size(), diff = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            diff = capacity[i] - rocks[i];
            if (diff == 0) ans++;
            else add_more.push_back(diff);
        }
        sort(add_more.begin(), add_more.end());
        int m = add_more.size();
        if (m == 0) return ans;
        for (int i = 1; i < m; i++) add_more[i] += add_more[i - 1];
        int ind = upper_bound(add_more.begin(), add_more.end(), 1ll*additionalRocks) - add_more.begin();
        return ans + ind;
    }
};