class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), diff = 0, max_diff = 0, mod = 1e9 + 7;
        long long sum_diff = 0;
        set<int> st(nums1.begin(), nums1.end());
        for(int i = 0; i < n; i++) {
            diff = abs(nums1[i] - nums2[i]);
            sum_diff += diff;
            auto it = st.lower_bound(nums2[i]);
            if(it != st.begin()) max_diff = max(max_diff, diff - abs(*prev(it) - nums2[i]));
            if(it != st.end()) max_diff = max(max_diff, diff - abs(*(it) - nums2[i]));
        }
        return (sum_diff - max_diff) % mod;
    }
};