class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0, val = 0, cnt = 0;
        map<int, int> mp;
        for (int &x : nums) mp[x]++;
        for (auto &it : mp) {
            val = it.first; cnt = it.second;
            if (cnt == 0 || val > k / 2) break;
            if (k % 2 == 0 && val == k / 2) {
                ans += cnt / 2;
                break;
            }
            else {
                if (mp.find(k - val) != mp.end()) ans += min(mp[val], mp[k - val]);
            }
        }
        return ans;
    }
};