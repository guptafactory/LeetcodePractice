class Solution {
    void dijkstra(vector<double> &prob, vector<pair<int, double>> adj[], int S)
    {
       priority_queue <pair<double, int>> pq;
        // {probability, node_no}
       prob[S] = 1;
       pq.push({1, S});
       while(!pq.empty()) {
           int node = pq.top().second;
           double prevProb = pq.top().first;
           pq.pop();
           for(auto it: adj[node]) {
               int adjNode = it.first;
               double newProb = it.second;
               if(prevProb * newProb > prob[adjNode]) {
                   prob[adjNode] = prevProb * newProb;
                   pq.push({prob[adjNode], adjNode});
               }
               
           }
       }
    }
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        int u = 0, v = 0;
        double prb = 0;
        vector<pair<int, double>> adj[n];
        vector<double> prob(n, 0);
        // creating adj list
        for(int i = 0; i < edges.size(); i++) {
            u = edges[i][0]; v = edges[i][1];
            prb = succProb[i];
            adj[u].push_back({v, prb});
            adj[v].push_back({u, prb});
        }
        // filling distance array
        dijkstra(prob, adj, start_node);
        return prob[end_node];
    }
};