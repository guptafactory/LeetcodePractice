class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        // val, cnt
        priority_queue<pair<int, int>> pq;
        for(int x: nums) mp[x]++;
        for(auto it: mp) pq.push({it.first, it.second});
        while(!pq.empty()) {
            int val = pq.top().first, cnt = pq.top().second;
            if(cnt >= k) return val;
            k -= cnt;
            pq.pop();
        }
        return -1;
    }
};