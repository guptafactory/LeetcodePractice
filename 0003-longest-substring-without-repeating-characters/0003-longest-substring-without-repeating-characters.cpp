class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(256, -1); // char -> last index
        int left = 0, n = s.length(), right = 0, len = 0;
        while(right < n) {
            if(mp[s[right]] != -1) left = max(mp[s[right]] + 1, left); // char already present
            mp[s[right]] = right; // update right ind always when get any char
            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};