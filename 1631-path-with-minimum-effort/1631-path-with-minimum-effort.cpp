class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size(), diff = 0, row = 0, col = 0, newRow = 0, newCol = 0, eff = 0, newEff = 0;
        priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        int delRow[4] = {-1, 0, 0, 1}, delCol[4] = {0, -1, 1, 0};
        
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        
        while(!pq.empty()) {
            diff = pq.top().first, row = pq.top().second.first, col = pq.top().second.second, eff = heights[row][col];
            pq.pop();
            if(row == n-1 && col == m-1) return diff;
            for(int k = 0; k < 4; k++) {
                newRow = row + delRow[k]; newCol = col + delCol[k];
                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                    newEff = max(diff, abs(eff - heights[newRow][newCol]));
                    if(newEff < dist[newRow][newCol]) {
                        dist[newRow][newCol] = newEff;
                        pq.push({newEff, {newRow, newCol}});
                    }
                }
            }
        }
        return 0;
    }
};