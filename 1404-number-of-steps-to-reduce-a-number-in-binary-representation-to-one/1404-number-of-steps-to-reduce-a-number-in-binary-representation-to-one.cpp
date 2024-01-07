class Solution {
public:
    int numSteps(string s) {
        int res = 0, ost = 0;
        for (int i = s.size() - 1; i > 0; --i) {
            int next_val = s[i] - '0' + ost;
            ost = (next_val == 2);
            ++res;
            if (next_val == 1)
                ++res, ost = 1;
        }
        return res + ost;
    }
};