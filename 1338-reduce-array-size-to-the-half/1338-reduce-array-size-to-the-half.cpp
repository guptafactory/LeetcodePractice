class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size(), cnt = 0, num = 0;
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < n; i++) mp[arr[i]]++;
        for(auto it: mp) pq.push({it.second, it.first});
        while(!pq.empty()) {
            cnt += pq.top().first; 
            num++;
            pq.pop();
            if(cnt >= n/2) break;
        }
        return num;
    }
};