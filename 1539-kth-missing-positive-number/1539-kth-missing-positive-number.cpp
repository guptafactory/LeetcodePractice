class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size(), low = 0, mid = 0, high = n - 1, missing;
        
        while(low <= high) {
            mid = low + (high-low)/2;
            missing = arr[mid] - (mid + 1);
            if(missing < k) low = mid + 1;
            else high = mid - 1;
        }
        
        return low + k;
        // return high + 1 + k;
    }
};