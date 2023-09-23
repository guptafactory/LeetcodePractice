class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int m = grades.size(), low = 1, mid = 0, high = m, ans = 0;
        long long temp = 0;
        while(low <= high) {
            mid = low + (high - low)/2;
            temp = 1ll*mid*(mid+1)/2;
            if(temp <= m) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};