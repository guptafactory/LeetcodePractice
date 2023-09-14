class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size(), i = 0, j = n-1;
        long long sum = skill[i] + skill[j], product = skill[i] * skill[j];
        i++; j--;
        while(i < j) {
            if(skill[i] + skill[j] != sum) return -1;
            product += skill[i] * skill[j];
            i++; j--;
        }
        return product;
    }
};