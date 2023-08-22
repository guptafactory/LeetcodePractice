//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
private:
    vector<int> ans;
    void subsetSum(int ind, int sum, int &n, vector<int> &arr) {
    if (ind == n) {
        ans.push_back(sum);
        return;
    }
    // not take
    subsetSum(ind + 1, sum, n, arr);
    // take
    subsetSum(ind + 1, sum + arr[ind], n, arr);
}
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        subsetSum(0, 0, N, arr);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends