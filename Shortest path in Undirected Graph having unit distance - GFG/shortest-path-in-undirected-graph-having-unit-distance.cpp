//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        vector<int> vis(N, 0), dist(N, INT_MAX);
        queue<pair<int, int>> que;
        for(int i = 0; i < M; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dist[src] = 0;
        que.push({src, 0});
        while(!que.empty()) {
            int node = que.front().first, wt = que.front().second;
            que.pop();
            for(int adjNode: adj[node]) {
                if(dist[adjNode] > wt + 1) {
                    dist[adjNode] = wt + 1;
                    que.push({adjNode, wt+1});
                }
            }
        }
        for(int i = 0; i < N; i++) {
            if(dist[i] == INT_MAX) dist[i] = -1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends