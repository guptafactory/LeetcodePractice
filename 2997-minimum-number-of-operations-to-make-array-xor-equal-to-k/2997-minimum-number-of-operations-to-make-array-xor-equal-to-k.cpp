class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int temp = 0, cnt = 0, lsb1 = 0, lsb2 = 0;
        for (int &x : nums) temp ^= x;
        while (temp || k) {
            lsb1 = (temp & 1);
            temp >>= 1;
            lsb2 = (k & 1);
            k >>= 1;
            if (lsb1 != lsb2) cnt++;
        }
        return cnt;
    }
};