class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size(), cnt = 0;
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto it: mp) cnt += abs(it.second);
        return cnt/2;
    }
};