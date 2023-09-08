class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, len = 0;
        for (int x: nums) {
            if (x == 0) {
                len++;
                ans += len;
            } else len = 0;
        }
        return ans;
    }
};