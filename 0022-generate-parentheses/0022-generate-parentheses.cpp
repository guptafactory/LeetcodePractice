class Solution {
private:
    void func(int open, int close, string str, vector<string> &ans) {
        if (open == 0 && close == 0) {
            ans.push_back(str);
            return;
        }
        if (open > 0) {
            str += '(';
            func(open - 1, close, str, ans);
            str.pop_back();
        }
        if (close > 0 && close > open) {
            str += ')';
            func(open, close - 1, str, ans);
            str.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        int open = n, close = n;
        string str;
        vector<string> ans;
        func(open, close, str, ans);
        return ans;
    }
};