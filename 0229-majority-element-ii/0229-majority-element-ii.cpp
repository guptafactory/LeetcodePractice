class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Boyer-Moore Voting Algo
        int n = nums.size(), cnt1 = 0, cnt2 = 0, maxm1 = 0, maxm2 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == maxm1) cnt1++;
            else if(nums[i] == maxm2) cnt2++;
            else if(cnt1 == 0) { maxm1 = nums[i]; cnt1 = 1; }
            else if(cnt2 == 0) { maxm2 = nums[i]; cnt2 = 1; }
            else { cnt1--; cnt2--; }
        }
        // verification
        cnt1 = 0; cnt2 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == maxm1) cnt1++;
            else if(nums[i] == maxm2) cnt2++;
        }
        vector<int> ans;
        if(cnt1 > n/3) ans.push_back(maxm1);
        if(cnt2 > n/3) ans.push_back(maxm2);
        return ans;
    }
};