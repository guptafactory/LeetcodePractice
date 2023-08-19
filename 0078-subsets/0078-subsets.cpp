class Solution {
private:
    vector<vector<int>> ans;
    void func(int ind, vector<int> &arr, int &n, vector<int> &nums)
    {
        if(ind == n) {
            ans.push_back(arr);
            return;
        }
        // not take
        func(ind + 1, arr, n, nums);
        // take
        arr.push_back(nums[ind]);
        func(ind + 1, arr, n, nums);
        arr.pop_back();
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        func(0, arr, n, nums);
        return ans;
    }
};