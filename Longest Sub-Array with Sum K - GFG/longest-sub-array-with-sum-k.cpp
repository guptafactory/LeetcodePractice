//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int nums[],  int N, int K) 
    { 
        int maxm = 0;
        long long sum = 0;
        map<long long, int> mp;
        for(int i = 0; i < N; i++) {
            sum += nums[i];
            if(sum == K) maxm = max(maxm, i+1);
            long long rem = sum - K;
            if(mp.find(rem) != mp.end()) maxm = max(maxm, i - mp[rem]);
            if(mp.find(sum) == mp.end()) mp[sum] = i;
        }
        return maxm;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends