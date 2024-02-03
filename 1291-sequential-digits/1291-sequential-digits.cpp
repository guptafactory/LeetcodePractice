class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int num;
        string str = "123456789", temp;
        for (int i = 0; i < 9; i++) {
            temp = "";
            for (int j = i; j < 9; j++) {
                temp += str[j];
                num = stoi(temp);
                if (num >= low && num <= high) ans.push_back(num);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};