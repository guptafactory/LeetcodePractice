class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int curr = nums[0], i = 1;
        for(int j = 1; j < n; j++) {
            if(nums[j] > curr) {
                nums[i++] = curr = nums[j];
            }
        }
        return i;
    }
    
};