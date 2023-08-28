class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int num = 0, rev = 0;
        set<int> st;
        for(int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
            num = nums[i]; 
            rev = 0;
            while(num) {
                rev *= 10;
                rev += num%10;
                num /= 10;
            }
            st.insert(rev);
        }
        return st.size();
    }
};