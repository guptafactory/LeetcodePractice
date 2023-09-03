class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int len = pattern.size();
        char ch = '0';
        string ptn; // contains normalised pattern string
        map<char, char> mp;
        vector<string> ans;
        for(int i = 0; i < len; i++) {
            if(mp.find(pattern[i]) == mp.end()) {
                mp[pattern[i]] = ch;
                ptn.push_back(ch);
                ch++;
            } else ptn.push_back(mp[pattern[i]]);
        }
        // cout << ptn << endl;
        for(int i = 0; i < words.size(); i++) {
            map<char, char> mp;
            string tmp;
            char ch = '0';
            for(int j = 0; j < len; j++) {
                if(mp.find(words[i][j]) == mp.end()) {
                    mp[words[i][j]] = ch;
                    tmp.push_back(ch);
                    ch++;
                } else tmp.push_back(mp[words[i][j]]);
            }
            // cout << tmp << endl;
            if(ptn == tmp) ans.push_back(words[i]);
        }
        return ans;
    }
};