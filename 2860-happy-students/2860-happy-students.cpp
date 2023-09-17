class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        if(nums[0] > 0) ans++;
        for(int i = 0; i < n-1; i++) {
            if(i >= nums[i] && i+1 < nums[i+1]) ans++;
        }
        if(n-1 >= nums[n-1]) ans++;
        return ans;
    }
};