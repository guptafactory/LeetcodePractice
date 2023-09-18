class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        int rem = nums.size() - k;
        for(int x: nums) {
            while(rem && ans.size() && x < ans.back()) {
                ans.pop_back();
                rem--;
            }
            ans.push_back(x);
        }
        while(rem--) ans.pop_back();
        return ans;
    }
};