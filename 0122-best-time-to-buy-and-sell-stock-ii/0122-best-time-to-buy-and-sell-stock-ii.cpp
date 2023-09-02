class Solution {
private:
    void func(int &ind, int &profit, int &prev, vector<int>& prices) {
        if(ind == -1) return;
        if(prices[ind] < prev) profit += prev - prices[ind]; 
        prev = prices[ind]; // Reset prev for next left prices
        ind--;
        func(ind, profit, prev, prices);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ind = n-1, profit = 0, prev = INT_MIN;
        func(ind, profit, prev, prices);
        return profit;
    }
};