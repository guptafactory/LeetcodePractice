class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++) mp[s[i]] = i; // char is mapped with index of its last occurence
        int start = 0, end = 0, cnt = 0;
        vector<int> arr;
        while(start < n) {
            int end = mp[s[start]];
            cnt = 0;
            while(start <= end) {
                if(mp[s[start]] > end) end = mp[s[start]]; // interval intersection
                start++;
                cnt++;
            }
            arr.push_back(cnt);
        }
        return arr;
        
    }
};