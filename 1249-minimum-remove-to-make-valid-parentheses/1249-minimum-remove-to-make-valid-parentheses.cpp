class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        vector<bool> arr(n, false);
        stack<int> st;
        string ans;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c >= 'a' && c <= 'z') arr[i] = true;
            else if (c == '(') st.push(i);
            else if (!st.empty()) { arr[st.top()] = arr[i] = true; st.pop(); }
        }
        for (int i = 0; i < n; i++) {
            if (arr[i]) ans += s[i];
        }
        return ans;
    }
};