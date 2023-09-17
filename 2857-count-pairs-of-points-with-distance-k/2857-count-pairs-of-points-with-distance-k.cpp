class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        map<pair<int, int>, int> mp;
        int ans = 0;
        for(int i = 0; i < coordinates.size(); i++) {
            int x1 = coordinates[i][0], y1 = coordinates[i][1];
            for(int j = 0; j <= k; j++) {
                int x2 = x1 ^ j, y2 = y1 ^ (k-j);
                // Let x1^x2 = 2, y1^y2 = k-2.
                // iterating from (0, k) -> (k, 0)
                ans += mp[{x2, y2}];
            }
            mp[{x1, y1}]++;
        }
        return ans;
    }
};