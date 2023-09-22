class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size(), cnt = 0;
        map<int, bool> mp;
        for(int i = 1; i <= 2000; i++) mp[i] = true;
        for(int i = 0; i < n; i++) mp[arr[i]] = false;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(it->second) {
                cnt++;
                if(cnt == k) return it->first;
            }
        }
        return -1;
    }
};