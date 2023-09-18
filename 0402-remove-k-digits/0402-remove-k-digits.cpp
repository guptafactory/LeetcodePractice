class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        for(char x: num) {
            while(k && ans.length() && x < ans.back()) {
                ans.pop_back();
                k--;
            }
            ans.push_back(x);
        }
        while(k--) ans.pop_back();
        while(ans[0] == '0') ans.erase(0, 1);
        if(ans.size() == 0) return "0";
        return ans;
    }
};