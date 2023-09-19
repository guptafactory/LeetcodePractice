class Solution {
private:
    int first_ind(int low, int high, vector<int> &arr, int &target) {
        int ind = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(arr[mid] == target) { ind = mid; high = mid-1; }
            else if(arr[mid] > target) high = mid-1;
            else low = mid+1;
        }
        return ind;
    }
    int last_ind(int low, int high, vector<int> &arr, int &target) {
        int ind = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(arr[mid] ==  target) { ind = mid; low = mid+1; }
            else if(arr[mid] > target) high = mid-1;
            else low = mid+1;
        }
        return ind;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int x = first_ind(0, n-1, nums, target), y = last_ind(0, n-1, nums, target);
        return {x, y};
    }
};