class Solution {
private:
    vector<vector<int>> ans;
    map<int, bool> mp;
    void permutation(vector<int> &arr, int &n, vector<int>& nums) {
        if(arr.size() == n) {
            ans.push_back(arr);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(mp[i] == 1) continue;
            arr.push_back(nums[i]);
            mp[i] = 1;
            permutation(arr, n, nums);
            arr.pop_back();
            mp[i] = 0;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        permutation(arr, n, nums);
        return ans;
    }
};