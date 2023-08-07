//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start == end) return 0;
        vector<int> dist(99999, INT_MAX);
        queue<pair<int, int>> que;
        int val = 0, steps = 0, newVal = 0, mod = 100000;
        que.push({start, 0});
        dist[start] = 0;
        while(!que.empty()) {
            int val = que.front().first, steps = que.front().second;
            que.pop();
            for(int x: arr) {
                newVal = (x%mod * val%mod) % mod;
                if(newVal == end) return (steps + 1);
                if(steps + 1 < dist[newVal]) {
                    dist[newVal] = steps + 1;
                    que.push({newVal, steps+1});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends