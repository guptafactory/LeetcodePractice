class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), temp = 0, ans = 0;
        // for every ith index, finding a kth index such that arr[i]..^..^..arr[k] == 0, then j can be from i + 1 to k
        for (int i = 0; i < n - 1; i++) {
            temp = arr[i];
            for (int j = i + 1; j < n; j++) {
                temp ^= arr[j];
                if (temp == 0) ans += j - i;
            }
        }
        return ans;
    }
};