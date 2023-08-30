class Solution {
public:
    string removeStars(string s) {
        string str = "";
        int cnt = 0, n = s.length();
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '*') cnt++;
            else if(cnt) {
                cnt--;
                continue;
            }
            else {
                str.push_back(s[i]);
            }
        }
        reverse(str.begin(), str.end());
        return str;
    }
};