class Solution {
private:
    vector<vector<string>> ans;
    void partition(int ind, string &str, vector<string> &arr) {
        if(ind == str.length()) {
            ans.push_back(arr);
            return;
        }
        for(int i = ind; i < str.length(); i++) {
            if(palindrome(str, ind, i)) {
                arr.push_back(str.substr(ind, i - ind + 1));
                partition(i+1, str, arr);
                arr.pop_back();
            }
        }
    }
    bool palindrome(string &str, int start, int end) {
        while(start <= end) {
            if(str[start++] != str[end--]) return false;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> arr;
        partition(0, s, arr);
        return ans;
    }
};