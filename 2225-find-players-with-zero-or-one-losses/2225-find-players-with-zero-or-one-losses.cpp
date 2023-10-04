class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> win, lost;
        for(int i = 0; i < matches.size(); i++) {
            win[matches[i][0]]++;
            lost[matches[i][1]]++;
        }
        vector<vector<int>> ans(2);
        for(auto it: win) { 
            if(lost[it.first] == 0) ans[0].push_back(it.first);
        }
        for(auto it: lost) {
            if(it.second == 1) ans[1].push_back(it.first);
        }
        return ans;
    }
};