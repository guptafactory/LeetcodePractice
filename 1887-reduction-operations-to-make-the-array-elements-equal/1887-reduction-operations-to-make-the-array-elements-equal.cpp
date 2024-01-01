class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size(), unique = 1, ans = 0, cnt = 0, last = 0;
        sort(nums.begin(), nums.end());
        if (nums[0] == nums[n - 1]) return 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) unique++;
        }
        cnt = 1; last = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] == last) cnt++;
            else {
                ans += (cnt * --unique);
                last = nums[i];
                cnt = 1;
            }
        }
        return ans;
    }
};