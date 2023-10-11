class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int m = pushed.size(), i = 0, j = 0;
        stack<int> st;
        while(i < m && j < m) {
            st.push(pushed[i]);
            while(!st.empty() && j < m && st.top() == popped[j]) { st.pop(); j++; }
            i++;
        }
        return st.empty();
    }
};