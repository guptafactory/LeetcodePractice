class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if(n == 0) return 0;
        string str = to_string(n);
        int m = str.length(), i = 1;
        while(i < m && str[i-1] <= str[i]) i++;
        while(i > 0 && i < m && str[i-1] > str[i]) { str[i-1]--; i--; }
        i++;
        while(i < m) { str[i] = '9'; i++; }
        m = 0;
        for(char ch: str) {
            m *= 10;
            m += (ch - '0');
        }
        return m;
    }
};