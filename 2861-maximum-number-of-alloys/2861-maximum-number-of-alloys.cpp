class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int max_alloys = 0;
        for(int i = 0; i < k; i++) // checking for every machine
        {
            int low = 0, high = 2*1e8;
            // mid -> Alloys needed
            while(low <= high) 
            {
                int mid = low + (high - low)/2;
                long long budget_needed = budget;
                for(int j = 0; j < n; j++) // looping over all machines
                {
                    long long metal_req = composition[i][j];
                    metal_req *= mid; 
                    metal_req -= stock[j];
                    if(metal_req < 0) continue; // current metal stock is more than required, check for next metal
                    long long additional_budget = metal_req * cost[j] * 1ll;
                    if(additional_budget > budget_needed) {
                        budget_needed = -1;
                        break;
                    }
                    budget_needed -= additional_budget;
                }
                if(budget_needed != -1) {
                    max_alloys = max(mid, max_alloys);
                    low = mid+1;
                }
                else high = mid-1; 
            }
        }
        return max_alloys;
    }
};