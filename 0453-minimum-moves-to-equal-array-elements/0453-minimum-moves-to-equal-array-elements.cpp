class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size(), sum = 0, minm = INT_MAX;
        for(int x: nums) {
            sum += x;
            minm = min(x, minm);
        }
        return sum - n*minm;
    }
};