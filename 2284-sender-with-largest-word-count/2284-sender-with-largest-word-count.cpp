class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> mp;
        int len = 0, max_len = 0;
        for(int i = 0; i < messages.size(); i++) {
            len = 0;
            for(int j = 0; j < messages[i].length(); j++) {
                if(messages[i][j] == ' ') len++;
            }
            len++;
            mp[senders[i]] += len;
        }
        string str = "";
        for(auto it: mp) {
            if(it.second > max_len) {
                str = it.first;
                max_len = it.second;
            } 
            else if(it.second == max_len && it.first > str) str = it.first;
        }
        return str;
    }
};