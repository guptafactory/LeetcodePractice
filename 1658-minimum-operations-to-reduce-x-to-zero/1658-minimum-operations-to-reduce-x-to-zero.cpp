class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), curr_sum = 0, max_window = -1, l = 0, r = 0, target_sum = 0;
        for(int val: nums) target_sum += val;
        target_sum -= x;
        while(r < n) {
            curr_sum += nums[r];
            while(l <= r && curr_sum > target_sum) {
                curr_sum -= nums[l];
                l++;
            }
            if(curr_sum == target_sum) {
                max_window = max(max_window, r - l + 1);
            }
            r++;
        }
        return (max_window == -1) ? -1 : n - max_window;
    }
};