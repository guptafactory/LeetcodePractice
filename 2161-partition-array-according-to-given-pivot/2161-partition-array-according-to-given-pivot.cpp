class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smaller;
        vector<int> greater;
        int cnt_pivot = 0;
        for (int &x : nums) {
            if (x < pivot) smaller.push_back(x);
            else if (x == pivot) cnt_pivot++;
            else greater.push_back(x);
        }
        while (cnt_pivot--) smaller.push_back(pivot);
        smaller.insert(smaller.end(), greater.begin(), greater.end());
        return smaller;
    }
};