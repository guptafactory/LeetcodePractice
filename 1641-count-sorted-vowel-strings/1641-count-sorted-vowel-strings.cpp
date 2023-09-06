class Solution {
public:
    int countVowelStrings(int n) {
        int arr[5] = {5, 4, 3, 2, 1};
        for (int i = 0; i < n-1; i++) {
            for(int j = 3; j >= 0; j--) arr[j] += arr[j+1];
        }
        return arr[0];
    }
};