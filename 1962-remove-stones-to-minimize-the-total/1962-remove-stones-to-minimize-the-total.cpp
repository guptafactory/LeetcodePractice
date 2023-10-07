class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int ans = 0;
        priority_queue<int> pq;
        for(int x: piles) pq.push(x);
        while(k--) {
            int x = pq.top();
            if(x == 0) { ans = -1; break; }
            pq.push(x - x/2);
            pq.pop();
        }
        if(ans == -1) return 0;
        while(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};