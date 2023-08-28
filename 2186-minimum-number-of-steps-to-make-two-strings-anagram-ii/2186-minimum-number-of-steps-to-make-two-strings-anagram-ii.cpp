class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size(), m = t.size(), cnt = 0;
        map<int, int> mp;
        for(int i = 0; i < n || i < m; i++) {
            if(i < n) mp[s[i]]++;
            if(i < m) mp[t[i]]--;
        }
        for(auto it: mp) cnt += abs(it.second);
        return cnt;
    }
};