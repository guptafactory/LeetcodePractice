class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), cnt = 0;
        unordered_map<int, int> mp;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            mp[A[i]]++;
            mp[B[i]]++;
            if(mp[A[i]] == 2) cnt++;
            if(A[i] != B[i] && mp[B[i]] == 2) cnt++;
            arr[i] = cnt;
        }
        return arr;
    }
};