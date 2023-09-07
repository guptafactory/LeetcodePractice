class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        ans.push_back(label);
        int lvl = log2(label), mr = 0;
        while(lvl) {
            mr = pow(2, lvl) + pow(2, lvl + 1) - 1 - label;
            // left_val + right_val - present_val (of that level) -> Gives mirror
            ans.push_back(mr/2); 
            label = mr/2; // next label is child of that mirror
            lvl--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};