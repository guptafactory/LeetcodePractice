class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(), low = INT_MAX, mid = 0, high = INT_MIN, cnt = 0, temp = 0, ans = 0;
        if(1ll*m*k > 1ll*n) return -1; // more flowers needed than possible
        for(int x: bloomDay) {
            low = min(low, x);
            high = max(high, x);
        }
        while(low <= high) {
            mid = low + (high - low)/2;
            cnt = 0, temp = 0;
            for(int x: bloomDay) {
                if(cnt == m) break;
                if(x > mid) temp = 0;
                else {
                    temp++;
                    if(temp == k) { cnt++; temp = 0; }
                }
            }
            if(temp == k) cnt++;
            if(cnt >= m) { ans = mid; high = mid-1; }
            else low = mid+1;
        }
        return ans;
    }
};