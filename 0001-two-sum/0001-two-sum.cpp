class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int n = nums.size(), rem = 0;
        for(int i = 0; i < n; i++) mp[nums[i]] = i;
        for(int i = 0; i < n; i++) {
            rem = target - nums[i];
            if(mp.find(rem) == mp.end() || mp[rem] == i) continue;
            else return {i, mp[rem]};
        }
        return {-1, -1};
    }
};