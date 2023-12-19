class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> arr;
        for(int i = 1; i*i <= n; i++) {
            if(n%i == 0) {
                arr.push_back(i);
                if(i*i != n) arr.push_back(n/i);
            }
        }
        sort(arr.begin(), arr.end());
        if(arr.size() < k) return -1;
        else return arr[k-1];
    }
};