class Solution {
public:
    int edgeScore(vector<int>& edges) {
        long long sum = 0, node = 0, n = edges.size();
        map<int, long long> mp;
        for(int i = 0; i < n; i++) mp[edges[i]] += i;
        for(auto it: mp) {
            if(it.second > sum) {
                sum = it.second;
                node = it.first;
            }
        }
        return node;
    } 
};