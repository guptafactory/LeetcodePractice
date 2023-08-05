class Solution {
    string b;
    
private:
    void dfs(string word, vector<string> &seq, map<string, int> &mpp, vector<vector<string>> &ans) {
        if(word == b) {
            ans.push_back(seq);
            return;
        }
        int steps = mpp[word], sz = word.size();
        for(int i = 0; i < sz; i++) {
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if(mpp.find(word) != mpp.end() && mpp[word] + 1 == steps) {
                    seq.push_back(word);
                    dfs(word, seq, mpp, ans);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
        
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set <string> st(wordList.begin(), wordList.end());
        map<string, int> mpp;
        vector<string> seq;
        queue<string> que;
        b = beginWord;
        que.push(b);
        mpp[b] = 1;
        st.erase(b);
        int sz = b.size();
        while(!que.empty()) {
            string word = que.front();
            int steps = mpp[word];
            que.pop();
            if(word == endWord) break;
            for(int i = 0; i < sz; i++) {
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(st.count(word)) {
                        que.push(word);
                        st.erase(word);
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }
        if(mpp.find(endWord) != mpp.end()) {
            seq.push_back(endWord);
            dfs(endWord, seq, mpp, ans);
        }
        for(vector<string> &vec : ans) reverse(vec.begin(), vec.end());
        return ans;
    }
};