class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size(), ind = 0, i = 0;
        queue<int> que;
        vector<int> ans(n);
        sort(deck.begin(), deck.end());
        
        for(int i = 0; i < n; i++) que.push(i);
        
        while(!que.empty()) {
            i = que.front();
            que.pop();
            
            ans[i] = deck[ind++];
            
            if(que.size() > 1) {
                int temp = que.front();
                que.pop();
                que.push(temp);
            }
            
        }
        
        return ans;
    }
};