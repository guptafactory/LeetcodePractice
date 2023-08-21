class Solution {
private:
    vector<vector<int>> ans;
    void sumCombination(int ind, int target, vector<int> &temp, int n, vector<int>& candidates) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        for(int i = ind; i < n; i++) {
            if(i > ind && candidates[i] == candidates[i-1]) continue; // same as previous element
            // i == ind already checking the value for next index, hence, same value can be taken
            if(candidates[i] > target) break; // no smaller value present
            temp.push_back(candidates[i]);
            sumCombination(i + 1, target - candidates[i], temp, n, candidates);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        sumCombination(0, target, temp, n, candidates);
        return ans;
    }
};