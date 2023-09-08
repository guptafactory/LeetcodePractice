class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(true) {
            // cout << n << ' ';
            if(n%3 == 2) return false;
            
            n /= 3;
            if(n == 0) return true;
        }
    }
};