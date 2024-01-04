class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0, ans = 0;
        map<int, int> mp;
        for (int &x : nums) mp[x]++;
        for (auto &it : mp) {
            cnt = it.second;
            if (cnt == 1) return -1;
            else ans += cnt / 3 + (bool)(cnt % 3);
        }
        return ans;
    }
};