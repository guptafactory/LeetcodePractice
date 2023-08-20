class Solution {
private:
    vector<vector<int>> ans;
    void sumCombination(int ind, int target, vector<int> &temp, int n, vector<int>& candidates) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        if(ind == n) return;
        // not take
        sumCombination(ind + 1, target, temp, n, candidates);
        // take
        temp.push_back(candidates[ind]);
        if(target >= candidates[ind]) sumCombination(ind, target - candidates[ind], temp, n, candidates);
        temp.pop_back();
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> temp;
        sumCombination(0, target, temp, n, candidates);
        return ans;
    }
};