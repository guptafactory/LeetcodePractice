class Solution {
public:
    int minFlips(string target) {
        int val = 0, flips = 0;
        for (char &c : target) {
            val = c - '0';
            if (val == flips % 2) continue;
            else flips++;
        }
        return flips;
    }
};