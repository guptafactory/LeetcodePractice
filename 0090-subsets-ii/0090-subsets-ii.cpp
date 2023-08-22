class Solution {
private:
    vector<vector<int>> ans;
    void subset(int ind, vector<int> &arr, int &n, vector<int> &nums) {
        if(ind == n) {
            ans.push_back(arr);
            return;
        }
        // not take
        subset(ind + 1, arr, n, nums);
        // take
        arr.push_back(nums[ind]);
        subset(ind + 1, arr, n, nums);
        arr.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        sort(nums.begin(), nums.end());
        subset(0, arr, n, nums);
        set<vector<int>> st;
        for(int i = 0; i < ans.size(); i++) st.insert(ans[i]);
        ans.clear();
        for(auto x: st) ans.push_back(x);
        return ans;
    }
};