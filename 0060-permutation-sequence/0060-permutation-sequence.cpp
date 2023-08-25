class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1, ind = 0; 
        string ans = "";
        
        vector<int> nums; // storing 1 to n
        for (int i = 1; i < n; i++) {
            fact *= i; // storing factorial of n-1
            nums.push_back(i);
        }
        nums.push_back(n);
        
        k--; // 0 based indexing -> Required index in every iteration
        
        while (true) {
            ind = k / fact;
            ans += to_string(nums[ind]);
            nums.erase(nums.begin() + ind);
            if(nums.size() == 0) break; // all elements placed & ans is calculated
            k = k % fact;
            fact = fact / nums.size();
        }
        
        return ans;
    }
};