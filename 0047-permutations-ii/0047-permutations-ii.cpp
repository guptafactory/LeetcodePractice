class Solution {
private:
    set<vector<int>> st;
    void permutation(int ind, int &n, vector<int>& nums) {
        if(ind == n) {
            st.insert(nums);
            return;
        }
        for(int i = ind; i < n; i++) {
            swap(nums[i], nums[ind]);
            permutation(ind + 1, n, nums);
            swap(nums[i], nums[ind]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        permutation(0, n, nums);
        vector<vector<int>> ans;
        for(auto x: st) ans.push_back(x);
        return ans;
    }
};