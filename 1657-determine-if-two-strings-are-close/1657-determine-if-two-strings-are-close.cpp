class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        if (n != m) return false;
        vector<int> arr1(26, 0), arr2(26, 0);
        for (char &c : word1) arr1[c - 'a']++;
        for (char &c : word2) arr2[c - 'a']++;
        // character not exist in another array, so can't be replaced
        for (int i = 0; i < 26; i++) {
            if ((arr1[i] == 0 && arr2[i] != 0) || (arr1[i] != 0 && arr2[i] == 0)) return false;
        }
        sort(arr1.begin(), arr1.end(), greater<int>());
        sort(arr2.begin(), arr2.end(), greater<int>());
        return arr1 == arr2;
    }
};