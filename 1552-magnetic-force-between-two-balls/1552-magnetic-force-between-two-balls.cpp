class Solution {
private:
    bool check(vector<int>& position, int dist, int m) {
        int cnt = 1, past = position[0];
        for(int x: position) {
            if(x - past >= dist) {
                cnt++;
                past = x; // update past to present value, for placing next ball (at a safe distance)
                if(cnt == m) return true; // m cows can be placed
            }
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size(), ans = 0;
        sort(position.begin(), position.end());
        int low = 0, mid = 0, high = position[n-1] - position[0];
        // mid represents the maxm safe distance possible b/w the consecutive pairs
        while(low <= high) {
            mid = low + (high-low)/2;
            if(check(position, mid, m)) {
                ans = mid;
                low = mid + 1; // all m balls can be placed at a safe distance, Now increase this distance
            } 
            else high = mid-1; // m balls can't be placed at a safe distances, Reduce this distance
        }
        return ans;
    }
};