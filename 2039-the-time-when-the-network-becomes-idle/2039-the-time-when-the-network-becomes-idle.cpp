class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size(), node, ans = 0, extra_packets;
        vector<int> time(n, INT_MAX);
        vector<int> adj[n];
        for(vector<int> it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int> que;
        que.push(0);
        time[0] = 0;
        while(!que.empty()) {
            node = que.front();
            que.pop();
            for(int adjNode: adj[node]) {
                if(time[node] + 1 < time[adjNode]) {
                    time[adjNode] = time[node] + 1;
                    que.push(adjNode);
                }
            }
        }
        for(int i = 1; i < n; i++) {
            time[i] *= 2; 
            // packet sent take some x time to master server, and receiving also takes same x time back to data server
            extra_packets = time[i] / patience[i];
            if(time[i] % patience[i] == 0) extra_packets--;
            ans = max(ans, time[i] + extra_packets * patience[i]);
            // time[i] represents 1st packet time to come back to data server
            // extra time due to extra packets should be added to above time
        }
        return ans + 1;
    }
};