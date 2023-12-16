class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kadane's Algorithm
        int maxm = INT_MIN, sum = 0;
        for(int &x: nums) {
            sum += x;
            if(sum > maxm) maxm = sum;
            if(sum < 0) sum = 0;
        }
        return maxm;
    }
};