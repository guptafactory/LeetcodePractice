class Solution {
private:
    static bool cmp(pair<int, string> &prA, pair<int, string> &prB) {
        // if freq same, return smaller string
        if (prA.first == prB.first) return (prA.second < prB.second);
        else return prA.first > prB.first;
    }
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        vector<pair<int, string>> arr;
        vector<string> ans;
        for(auto &str: words) mp[str]++;
        for(auto it: mp) arr.push_back({it.second, it.first});
        sort(arr.begin(), arr.end(), cmp);
        int i = 0;
        while(k--) ans.push_back(arr[i++].second);
        return ans;
    }
};