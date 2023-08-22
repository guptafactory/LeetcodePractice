//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{ 
private:
    int dp[101][10001];
    int subsetSum(int ind, int sum, vector<int> &arr) {
    if (sum == 0) return 1;
    if (ind <= 0) return 0;
    
    if (dp[ind - 1][sum] != -1) return dp[ind - 1][sum];
    
    if (arr[ind - 1] > sum) return dp[ind - 1][sum] = subsetSum(ind - 1, sum, arr);
    
    else return dp[ind - 1][sum] = subsetSum(ind - 1, sum, arr) || subsetSum(ind - 1, sum - arr[ind - 1], arr);
}
public:
    bool isSubsetSum(vector<int>arr, int sum) {
        memset(dp, -1, sizeof(dp));
        int n = arr.size();
        return (bool)subsetSum(n, sum, arr);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends