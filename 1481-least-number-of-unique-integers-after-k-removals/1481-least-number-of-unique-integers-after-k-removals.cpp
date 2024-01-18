class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int val = 0;
        map<int, int> mp;
        for (int &x : arr) mp[x]++;
        vector<int> nums;
        for (auto &it : mp) nums.push_back(it.second);
        sort(nums.begin(), nums.end(), greater<int>());
        while (!nums.empty() && k > 0) {
            val = nums.back();
            if (val > k) break;
            nums.pop_back();
            k -= val;
        }
        return nums.size();
    }
};