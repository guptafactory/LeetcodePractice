//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st) {
        vis[node] = 1;
        for(int adjNode: adj[node]) {
            if(!vis[adjNode]) dfs(adjNode, vis, adj, st);
        }
        // Lower finishing time nodes will be stored early/lower in stack
        st.push(node);
    }
    void finalDFS(int node, vector<int> &arr, vector<int> &vis, vector<vector<int>> &adjRev) {
        vis[node] = 1;
        arr.push_back(node);
        for(int adjNode: adjRev[node]) {
            if(!vis[adjNode]) finalDFS(adjNode, arr, vis, adjRev);
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        int node = 0;
        vector<int> vis(V, 0), arr;
        vector<vector<int>> adjRev(V), ans;
        stack<int> st;
        // sorting nodes by finishing time
        for(int i = 0; i < V; i++) {
            if(!vis[i]) dfs(i, vis, adj, st);
        }
        // reversing graph
        for(int i = 0; i < V; i++) {
            vis[i] = 0;
            for(int j = 0; j < adj[i].size(); j++) adjRev[adj[i][j]].push_back(i);
        }
        // final dfs
        while(!st.empty()) {
            node = st.top();
            st.pop();
            if(!vis[node]) finalDFS(node, arr, vis, adjRev);
            if(!arr.empty()) ans.push_back(arr);
            arr.clear();
        }
        return ans.size();
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends