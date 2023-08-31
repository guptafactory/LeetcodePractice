class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multimap<int, vector<int>> mp;
        vector<vector<int>> ans;
        for(int i = 0; i < points.size(); i++) {
            int dist = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            mp.insert({dist, points[i]});
        }
        auto it = mp.begin();
        while(k--) {
            ans.push_back(it->second);
            it++;
        }
        return ans;
    }
};