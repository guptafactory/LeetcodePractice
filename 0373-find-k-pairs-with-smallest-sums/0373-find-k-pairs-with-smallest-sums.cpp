class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                int sum = nums1[i] + nums2[j];
                
                if(pq.size() < k) pq.push({sum, {i, j}});
                else if(pq.top().first > sum) { pq.pop(); pq.push({sum, {i, j}}); }
                else break;
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            int u = pq.top().second.first, v = pq.top().second.second;
            pq.pop();
            ans.push_back({nums1[u], nums2[v]});
        }
        return ans;
    }
};