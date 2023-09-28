class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0; i < nums.size()-1; i++) {
            // check if adjusted index is Even and consecutive elements are same 
            if((i-cnt)%2 == 0 && nums[i] == nums[i+1]) cnt++;
        }
        if((nums.size() - cnt)%2) cnt++; // array size is odd, remove last element
        return cnt;
    }
};