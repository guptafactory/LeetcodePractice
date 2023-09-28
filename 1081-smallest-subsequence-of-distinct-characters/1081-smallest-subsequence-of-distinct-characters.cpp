class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        string res; // monotonic stack can be used
        vector<bool> taken(26, false);
        vector<int> last_ind(26);
        
        for(int i = 0; i < n; i++) last_ind[s[i]-'a'] = i; // storing last ind of all alphabets
        for(int i = 0; i < n; i++) {
            if(taken[s[i]-'a'] == true) continue; // char already present in string, Don't take again
            while(res.length() && (res.back() > s[i]) && (last_ind[res.back()-'a'] > i)) {
                // present character is small and previous character has a duplicate at a larger index present
                // so safely remove previous chars
                taken[res.back()-'a'] = false;
                res.pop_back();
            }
            res.push_back(s[i]);
            taken[s[i]-'a'] = true;
        }
        return res;
    }
};