class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        // {cnt, val} in sorted
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        for(int x: nums) mp[x]++;
        for(auto it: mp) pq.push({it.second, it.first});
        while(k--) {
            int num = pq.top().second;
            pq.pop();
            ans.push_back(num);
        }
        return ans;
    }
};