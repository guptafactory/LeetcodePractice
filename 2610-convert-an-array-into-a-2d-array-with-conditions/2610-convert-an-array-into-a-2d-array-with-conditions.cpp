class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = 0;
        for(int i = 0; i < nums.size(); i++) mp[nums[i]]++; // count of all variables
        for(auto it: mp) n = max(n, it.second); // maxm cnt of any variable => No. of rows
        
        vector<vector<int>> arr(n);
        for(auto it: mp) {
            for(int i = 0; i < it.second; i++) arr[i].push_back(it.first);
        }
        return arr;
    }
};