//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
private:
    bool isSafe(int node, bool graph[101][101], vector<int> &color, int &n, int clr) {
        for(int adjNode = 0; adjNode < n; adjNode++) {
            if(graph[adjNode][node] == 1 && adjNode != node && color[adjNode] == clr) return false;
        }
        return true;
    }
    bool solve(int node, bool graph[101][101], vector<int> &color, int &m, int &n) {
        if(node == n) return true; // if all nodes can be colored
        for(int clr = 1; clr <= m; clr++) {
            // checking all safe colors on given node
            if(isSafe(node, graph, color, n, clr)) {
                color[node] = clr;
                if(solve(node + 1, graph, color, m, n)) return true;
                color[node] = 0;
            }
        }
        return false; // if given node can't be colored in any color
    }
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> color(n, 0);
        return solve(0, graph, color, m, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends