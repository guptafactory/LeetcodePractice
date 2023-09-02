class Solution {
private:
    void func(int &ind, int &diff, int &minm, int &maxm, vector<int>& prices) {
        if(ind == -1) return;
        if(prices[ind] > maxm) maxm = minm = prices[ind]; // Reset minm & find left smallest value for this maxm
        if(prices[ind] < minm) minm = prices[ind]; // got a negative for the past maxm
        diff = max(maxm - minm, diff);
        ind--;
        func(ind, diff, minm, maxm, prices);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ind = n-1, diff = 0, minm = INT_MAX, maxm = INT_MIN;
        func(ind, diff, minm, maxm, prices);
        return diff;
    }
};