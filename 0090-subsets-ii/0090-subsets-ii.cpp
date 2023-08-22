class Solution {
private:
    vector<vector<int>> ans;
    void subset(int ind, vector<int> &arr, int &n, vector<int> &nums) {
        ans.push_back(arr);
        for(int i = ind; i < n; i++) {
            if(i != ind && nums[i] == nums[i-1]) continue;
            arr.push_back(nums[i]);
            subset(i + 1, arr, n, nums);
            arr.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        sort(nums.begin(), nums.end());
        subset(0, arr, n, nums);
        return ans;
    }
};