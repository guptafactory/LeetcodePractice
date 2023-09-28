class Solution {
public:
    int minDeletions(string s) {
        int del = 0, temp = 0;
        vector<int> freq(26, 0);
        for(int i = 0; i < s.length(); i++) freq[s[i]-'a']++;
        sort(freq.begin(), freq.end());
        for(int i = 24; i >= 0 && freq[i] > 0; i--) {
            if(freq[i] >= freq[i+1]) {
                temp = freq[i];
                freq[i] = max(freq[i+1] - 1, 0);
                del += temp - freq[i];
            }
        }
        return del;
    }
};