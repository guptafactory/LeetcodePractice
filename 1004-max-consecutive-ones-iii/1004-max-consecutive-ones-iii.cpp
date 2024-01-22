class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size();
        while (j < n) {
            if (nums[j] == 0) k--; // including right pointer
            if (k < 0) { // checking invalidity
                if (nums[i] == 0) k++;
                i++; // shrinking left pointer irrespective if '0' or '1'
            }
            j++;
        }
        return j - i;
    }
};