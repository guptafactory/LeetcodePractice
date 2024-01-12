class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length(), half = n / 2, cnt1 = 0, cnt2 = 0;
        set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for (int i = 0; i < half; i++) {
            if (st.find(s[i]) != st.end()) cnt1++;
        }
        for (int i = half; i < n; i++) {
            if (st.find(s[i]) != st.end()) cnt2++;
        }
        return cnt1 == cnt2;
    }
};