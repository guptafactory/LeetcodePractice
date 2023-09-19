class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for(int x: nums){
            if(mp[x] == true) return x;
            else mp[x] = true;
        }
        return -1;
    }
};