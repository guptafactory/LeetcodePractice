class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size(), low = 1, mid = 0, high = INT_MIN, ans = 1;
        long long sum = 0;
        
        for(int x: nums) {
            high = max(high, x);
            sum += x;
        }
        if(threshold >= sum) return 1;
        if(n == threshold) return high;
            
        while(low <= high) {
            mid = low + (high-low)/2;
            sum = 0;
            for(int x: nums) {
                sum += ceil((double)x/mid);
                if(sum > threshold) break;
            }
            if(sum > threshold) low = mid+1;
            else { ans = mid; high = mid-1; }
        }
        return ans;
    }
};