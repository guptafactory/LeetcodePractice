class Solution {
private:
    int sum_digits(int x) {
        int sum = 0;
        while (x) { sum += x % 10; x /= 10; };
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        int sum = 0, ans = -1;
        vector<vector<int>> arr(82);
        for (int &x : nums) {
            sum = sum_digits(x);
            arr[sum].push_back(x);
        }
        for (int i = 0; i < 82; i++) {
            if (arr[i].size() <= 1) continue;
            sort(arr[i].begin(), arr[i].end(), greater<int>());
            ans = max(ans, arr[i][0] + arr[i][1]);
        }
        return ans;
    }
};