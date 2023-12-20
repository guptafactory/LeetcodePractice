class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size(), xor_arr = 0, ind_0 = 0;
        vector<int> perm(n+1);
        for(int i = 1; i <= n+1; i++) xor_arr ^= i;
        for(int i = 1; i < n; i+=2) xor_arr ^= encoded[i];
        perm[0] = xor_arr;
        for(int i = 0; i < n; i++) perm[i+1] = perm[i]^encoded[i];
        return perm;
    }
};