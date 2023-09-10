class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();
        vector<bool> ans;
        
        for(int i = 0; i < m; i++) {
            vector<int> temp(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(temp.begin(), temp.end());
            int diff = temp[1] - temp[0];
            int equal = 1;
            
            for(int j = 2; j < temp.size(); j++) {
                if(temp[j] - temp[j-1] != diff) {
                    ans.push_back(false);
                    equal = 0; break;
                } 
            }
            if(equal) ans.push_back(true);
        }
        
        return ans;
    }
};