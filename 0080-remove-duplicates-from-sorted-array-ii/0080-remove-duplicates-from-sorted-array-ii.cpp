class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), cnt = 0, maxm = INT_MIN, i = 0;
        
        for(int j = 0; j < n; j++) {
            if(nums[j] > maxm) {
                nums[i++] = maxm = nums[j];
                cnt = 1;
            }
            else if(cnt == 1) {
                nums[i++] = maxm;
                cnt++;
            }
            else cnt++;
        }
        
        return i;
    }
};