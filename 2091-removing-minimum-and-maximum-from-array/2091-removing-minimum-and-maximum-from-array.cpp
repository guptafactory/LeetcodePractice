class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size(), maxm = -1e5-1, x = 0, minm = 1e5+1, y = 0;
        if(n == 1) return 1;
        for(int i = 0; i < n; i++) {
            if(nums[i] > maxm) { maxm = nums[i]; x = i+1; }
            if(nums[i] < minm) { minm = nums[i]; y = i+1; }
        }
        return min({max(x, y), max(n-x+1, n-y+1), (n-x+1 + y), (x + n-y+1)});
    }
};