class Solution {
private:
    void func(int ind, string temp, int &n, string &s, vector<string> &ans) {
        if (ind == n) {
            ans.push_back(temp);
            return;
        }
        // digit
        if (s[ind] >= '0' && s[ind] <= '9') {
            temp += s[ind];
            func(ind + 1, temp, n, s, ans);
        }
        else {
            // alphabet & lowercase
            temp += tolower(s[ind]);
            func(ind + 1, temp, n, s, ans);
            temp.pop_back();
            // alphabet & uppercase
            temp += toupper(s[ind]);
            func(ind + 1, temp, n, s, ans);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        int n = s.length(), ind = 0;
        vector<string> ans;
        string temp;
        func(ind, temp, n, s, ans);
        return ans;
    }
};