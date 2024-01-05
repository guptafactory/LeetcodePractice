class Solution {
public:
    string arrangeWords(string text) {
        multimap<int, string> mp;
        text[0] = tolower(text[0]);
        string str, ans;
        for (char &c : text) {
            if (c == ' ') {
                mp.insert({str.size(), str});
                str = "";
            }
            else str += c;
        }
        mp.insert({str.size(), str});
        for (auto it : mp) {
            ans += it.second;
            ans += " ";
        }
        // cout << ans << endl;
        ans.pop_back();
        ans[0] = toupper(ans[0]);
        return ans;
    }
};