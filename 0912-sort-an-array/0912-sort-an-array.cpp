class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size(), i = 0;
        vector<int> ans(n);
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int &x: nums) pq.push(x);
        while(!pq.empty()) {
            int x = pq.top();
            pq.pop();
            ans[i++] = x;
        }
        return ans;
    }
};