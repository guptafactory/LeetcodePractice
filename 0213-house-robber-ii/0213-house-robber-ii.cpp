class Solution {
private:
    int func3(vector<int> &nums) {
        int n = nums.size(), prev_2 = 0, prev = 0, curr = 0, pick = 0, not_pick = 0;
        prev_2 = 0;
        prev = nums[0];
        for (int i = 1; i < n; i++) {
            pick = nums[i];
            if(i > 1) pick += prev_2;
            not_pick = prev;
            curr = max(pick, not_pick);
            prev_2 = prev;
            prev = curr;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> temp1, temp2;
        // temp1 stores [0...n-2]
        // temp2 stores [1...n-1]
        for(int i = 0; i < n; i++) {
            if(i != 0) temp2.push_back(nums[i]);
            if(i != n-1) temp1.push_back(nums[i]);
        }
        return max(func3(temp1), func3(temp2));
    }
};