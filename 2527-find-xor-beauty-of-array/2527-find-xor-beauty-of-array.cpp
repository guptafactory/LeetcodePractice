class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int ans = 0;
        for(int x: nums) ans ^= x;
        return ans;
    }
};