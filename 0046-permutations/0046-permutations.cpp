class Solution {
private:
    vector<vector<int>> ans;
    map<int, bool> mp;
    void permutation(int ind, int &n, vector<int>& nums) {
        if(ind == n) {
            ans.push_back(nums);
            return;
        }
        for(int i = ind; i < n; i++) {
            swap(nums[i], nums[ind]);
            permutation(ind + 1, n, nums);
            swap(nums[i], nums[ind]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        permutation(0, n, nums);
        return ans;
    }
};