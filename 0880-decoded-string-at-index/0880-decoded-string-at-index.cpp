class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long size = 0, n = s.size();
        // measuring length of encoded string
        for(int i = 0; i < n; i++) {
            if(isdigit(s[i])) size *= s[i] - '0';    
            else size++;
        }
        for(int i = n-1; i >= 0; i--) {
            k %= size;
            if(k == 0 && isalpha(s[i])) return string(1, s[i]);
            else if(isalpha(s[i])) size--;
            else size /= s[i] - '0';
        }
        return "";
    }
};