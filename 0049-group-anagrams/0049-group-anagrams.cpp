class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        string str;
        map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            str = strs[i];
            sort(str.begin(), str.end());
            mp[str].push_back(strs[i]);
        }
        for (auto &it : mp) ans.push_back(it.second);
        return ans;
    }
};