class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n = logs.size(), birth = 0, death = 0, maxm = 0, ind = 0;
        vector<int> arr(1001, 0);
        for(int i = 0; i < n; i++) {
            birth = logs[i][0];
            death = logs[i][1];
            while(birth < death) {
                arr[birth-1950]++;
                birth++;
            }
        }
        for(int i = 0; i < 1001; i++) {
            if(arr[i] > maxm) {
                maxm = arr[i];
                ind = i;
            }
            
        }
        return ind + 1950;
    }
};