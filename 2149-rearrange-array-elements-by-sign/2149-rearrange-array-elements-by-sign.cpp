class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(), pos = 0, neg = 1;
        vector<int> ans(n);
        for(int &x: nums) {
            if(x > 0) { ans[pos] = x; pos += 2; }
            else { ans[neg] = x; neg += 2; }
        }
        return ans;
    }
};