class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) return 0;
        int val = kthGrammar(n - 1, (k + 1) / 2);
        if (k & 1) return val;
        else return !val;
    }
};