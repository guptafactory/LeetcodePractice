class Solution {
private:
    bool possible(int limit, int &allowed_days, vector<int>& weights) {
        int sum = 0, days = 1;
        for(int wt: weights) {
            sum += wt;
            if(days > allowed_days) return false;
            if(wt > limit) return false;
            if(sum > limit) {
                days++;
                sum = wt;
            }
        }
        return (days <= allowed_days) ? true : false;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0, mid = 0, high = 0, n = weights.size();
        for(int wt: weights) {
            low = max(low, wt);
            high += wt;
        }
        int ans = high;
        while(low <= high) {
            mid = low + (high - low)/2;
            if(possible(mid, days, weights) == true) {
                ans = mid;
                high = mid - 1;
            } 
            else low = mid + 1;
        }
        return ans;
    }
};