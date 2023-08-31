class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int extra_rungs = 0, diff = 0;
        extra_rungs += ceil((double)rungs[0]/dist) - 1;
        for(int i = 1; i < rungs.size(); i++) {
            diff = rungs[i] - rungs[i-1];
            if(diff > dist) extra_rungs += ceil((double)diff/dist) - 1;
        }
        return extra_rungs;
    }
};