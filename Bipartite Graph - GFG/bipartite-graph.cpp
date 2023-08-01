//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool componentBipartite(int start, vector<int> &color, vector<int>adj[]) {
        queue<int> que;
        que.push(start);
        color[start] = 0;
        while(!que.empty()) {
            int node = que.front();
            que.pop();
            for(int adjNode: adj[node]) {
                if(color[adjNode] == -1) {
                    color[adjNode] = !color[node];
                    que.push(adjNode);
                }
                else if(color[adjNode] == color[node]) return false;   
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
        vector<int> color(V, -1);
        for(int i = 0; i < V; i++) {
            if(color[i] == -1 && !componentBipartite(i, color, adj)) return false;
        }
        return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends