class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int last_cnt = 0, cnt = 0, ans = 0;
        for (string &str : bank) {
            cnt = 0;
            for (char &c : str) {
                if (c == '1') cnt++;
            }
            if (cnt == 0) continue;
            else {
                ans += cnt * last_cnt;
                last_cnt = cnt;
            }
        }
        return ans;
    }
};