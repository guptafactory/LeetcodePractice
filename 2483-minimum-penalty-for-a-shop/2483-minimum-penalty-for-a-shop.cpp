class Solution {
public:
    int bestClosingTime(string customers) {
        int tot_yes = 0, tot_no = 0, prev_yes = 0, prev_no = 0, fwd_yes = 0, fwd_no = 0;
        for (char &c : customers) {
            if (c == 'Y') tot_yes++;
            else tot_no++;
        }
        int n = customers.length(), penalty = n, ind = n;
        if (tot_yes == 0) return 0;
        if (tot_no == 0) return n;
        for (int i = 0; i < n; i++) {
            fwd_yes = tot_yes - prev_yes;
            if (prev_no + fwd_yes < penalty) {
                penalty = prev_no + fwd_yes;
                ind = i;
            }
            if (customers[i] == 'Y') prev_yes++;
            else prev_no++;
        }
        if (tot_no < penalty) ind = n;
        return ind;
    }
};