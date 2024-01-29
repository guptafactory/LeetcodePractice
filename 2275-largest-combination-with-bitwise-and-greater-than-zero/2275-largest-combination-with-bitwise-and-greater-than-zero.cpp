class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size(), ans = 0;
        for (int k = 0; k < 25; k++) {
            int one = 0;
            for (int i = 0; i < n; i++) {
                if (candidates[i] & 1) one++;
                candidates[i] >>= 1;
            }
            ans = max(ans, one);
        }
        return ans;
    }
};