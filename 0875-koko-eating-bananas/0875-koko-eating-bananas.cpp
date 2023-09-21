class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(), low = 1, k = 0, high = 1e9, time = 0, ans = INT_MAX;
        sort(piles.begin(), piles.end());
        while(low <= high) {
            k = low + (high-low)/2;
            time = 0;
            for(int x: piles) {
                time += ceil(x / (double)k);
                if(time > h) break;
            }
            if(time > h) low = k + 1; // increase eating speed
            else { ans = min(ans, k); high = k - 1; } // decrease eating speed
        }
        return ans;
    }
};