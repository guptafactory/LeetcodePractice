class Solution {
public:
    string frequencySort(string s) {
        string str;
        unordered_map <char, int> mp;
        vector<pair<int, char>> arr;
        for(char c: s) mp[c]++;
        for(auto it: mp) arr.push_back({it.second, it.first});
        sort(arr.rbegin(), arr.rend());
        for(auto pr: arr) {
            for(int i = 0; i < pr.first; i++) str.push_back(pr.second);
        }
        return str;
    }
};