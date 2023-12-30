class Solution {
public:
    int minSwaps(string s) {
        int one = 0, zero = 0, flag1 = 0, cnt1 = 0, flag2 = 1, cnt2 = 0;
        for (char &c : s) {
            if (c == '0') {
                zero++;
                if (flag1) cnt1++;
                if (flag2) cnt2++;
            }
            else {
                one++;
                if (!flag1) cnt1++;
                if (!flag2) cnt2++;
            }
            flag1 ^= 1;
            flag2 ^= 1;
        }
        if (abs(one - zero) > 1) return -1;
        if (zero == one) return min(cnt1 / 2, cnt2 / 2);
        if (zero > one) return cnt1 / 2;
        else return cnt2 / 2;
    }
};