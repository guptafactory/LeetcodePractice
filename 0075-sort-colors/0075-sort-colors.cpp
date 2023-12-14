class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = 0, n = nums.size();
        for(int &x: nums) {
            if(x == 0) zero++;
            else if(x == 1) one++;
            else two++;
        }
        for(int i = 0; i < n; i++) {
            if(zero) { nums[i] = 0; zero--; }
            else if(one) { nums[i] = 1; one--; }
            else { nums[i] = 2; two--; }
        }
    }
};