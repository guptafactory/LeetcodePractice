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
        vector<pair<int, int>> arr(82, pair<int, int> { -1, -1});
        for (int &x : nums) {
            sum = sum_digits(x);
            if (arr[sum].second == -1) arr[sum].second = x;
            else if (arr[sum].second <= x) {
                arr[sum].first = arr[sum].second;
                arr[sum].second = x;
            }
            else arr[sum].first = max(arr[sum].first, x);
        }
        for (int i = 0; i < 82; i++) {
            if (arr[i].first == -1) continue;
            ans = max(ans, arr[i].first + arr[i].second);
        }
        return ans;
    }
};