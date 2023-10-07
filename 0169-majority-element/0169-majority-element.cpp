class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyer-Moore Voting Algo
        int n = nums.size(), cnt = 1, maxm = nums[0];
        for(int i = 1; i < n; i++) {
            if(cnt == 0) { maxm = nums[i]; cnt = 1; }
            else if(nums[i] == maxm) cnt++;
            else cnt--;
        }
        // verification
        cnt = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == maxm) cnt++;
        }
        if(cnt > n/2) return maxm;
        else return -1;
    }
};