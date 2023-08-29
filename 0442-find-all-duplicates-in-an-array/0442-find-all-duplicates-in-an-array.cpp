class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            // value at that index is -ve -> abs(present value) is repeated
            if(nums[abs(nums[i]) - 1] < 0) ans.push_back(abs(nums[i]));
            // negate the value at that index
            else nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }
        return ans;
    }
};