class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.length(), flag = 0, tempA = 0, tempB = 0, cntA = 0, cntB = 0;
        if(colors[0] == 'B') flag = 1;
        for(int i = 0; i < n; i++) {
            if(flag == 0 && colors[i] == 'A') tempA++;
            else if(flag == 0 && colors[i] == 'B') {
                flag ^= 1;
                cntA += max(tempA-2, 0);
                tempB = 1;
            }
            else if(flag == 1 && colors[i] == 'B') tempB++;
            else if(flag == 1 && colors[i] == 'A') {
                flag ^= 1;
                cntB += max(tempB-2, 0);
                tempA = 1;
            }
        }
        if(flag == 0) cntA += max(tempA-2, 0);
        if(flag == 1) cntB += max(tempB-2, 0);
        
        if(cntA == 0) return false;
        return (cntA > cntB) ? true : false; 
    }
};