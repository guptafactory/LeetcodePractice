class Solution {
private:
    void helper(set<string> &st) {
        long N = 1e9, n = 1;
        string str;
        while (n <= N) {
            str = to_string(n);
            sort(str.begin(), str.end());
            st.insert(str);
            n <<= 1;
        }
    }
public:
    bool reorderedPowerOf2(int n) {
        set<string> st;
        helper(st);
        string str = to_string(n);
        sort(str.begin(), str.end());
        if (st.find(str) == st.end()) return false;
        else return true;
    }
};