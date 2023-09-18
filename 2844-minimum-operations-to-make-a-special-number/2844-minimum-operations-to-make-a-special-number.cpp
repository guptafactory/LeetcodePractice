class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        bool five = false, zero = false;
        for(int i = n-1; i >= 0; i--) {
            if(zero && (num[i] == '0' || num[i] == '5')) return n-i-2; // 00, 50 
            if(five && (num[i] == '2' || num[i] == '7')) return n-i-2; // 25, 75
            // n-i -> represents sliding window like [5, 7, 7, 0]
            // subtract 2 values from this, as these 2 digits are to be saved (no deletion)
            if(num[i] == '0') zero = true;
            if(num[i] == '5') five = true;
        }
        if(zero) return n-1; // one zero is present, rest remove all digits
        return n; // no zero is present, delete all digits, 0 is divisible by 25
    }
};