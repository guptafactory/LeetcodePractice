class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int curr_capacity = 0;
        vector<int> change_in_passengers(1001);
        for (vector<int> &trip : trips) {
            change_in_passengers[trip[1]] += trip[0];
            change_in_passengers[trip[2]] -= trip[0];
        }
        for (int i = 0; i < 1001; i++) {
            if (change_in_passengers[i] == 0) continue;
            curr_capacity += change_in_passengers[i];
            if (curr_capacity > capacity) return false;
        }
        return true;
    }
};