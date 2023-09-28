class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0, j = n-1; i < j;) {
            if(nums[i]%2 != 0) {
                if(nums[j]%2 == 0) { swap(nums[i], nums[j]); i++; j--; } // {odd, even}
                else j--;// {odd, odd}
            } else i++;
        }
        return nums;
    }
};