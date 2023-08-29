class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, bool> mp;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            if(mp[nums[i]] == true) ans.push_back(nums[i]);
            else mp[nums[i]] = true;
        }
        return ans;
    }
};