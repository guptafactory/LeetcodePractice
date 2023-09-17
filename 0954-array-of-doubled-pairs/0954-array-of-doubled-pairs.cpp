class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> mp;
        vector<int> keys;
        for(int x: arr) mp[x]++;
        for(auto x: mp) keys.push_back(x.first);
        sort(keys.begin(), keys.end(), [](int i, int j) {return abs(i) < abs(j);});
        // sorted in abs value but with signs
        // 2 -2 -4 4 
        for(int x: keys) {
            if(mp[x] > mp[2*x]) return false; // count of smaller value is more
            mp[2*x] -= mp[x];
        }
        return true;
    }
};