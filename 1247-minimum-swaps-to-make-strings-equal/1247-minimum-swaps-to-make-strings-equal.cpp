class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s1.length(), x_mis = 0, y_mis = 0;
        for(int i = 0; i < n; i++) {
            if(s1[i] == 'x' && s2[i] == 'y') x_mis++;
            else if(s1[i] == 'y' && s2[i] == 'x') y_mis++;
        }
        if(x_mis % 2 != y_mis % 2) return -1;
        int ans = x_mis/2 + y_mis/2; // pair swapping (1 move required) (as shown in 1st example)
        if(x_mis % 2 == 1) ans += 2; // 1 extra mismatch -> this needs 2 swaps (as shown in 2nd example)
        return ans;
    }
};