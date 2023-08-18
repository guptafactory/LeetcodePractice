/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void dfs(TreeNode* root, int cnt, vector<pair<int, int>> &arr) {
        if(root-> left == NULL && root->right == NULL) { 
            arr.push_back({cnt, root->val}); 
            return; 
        }
        cnt++;
        if(root->left != NULL) dfs(root->left, cnt, arr);
        if(root->right != NULL) dfs(root->right, cnt, arr);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        // level, node_value
        vector<pair<int, int>> arr;
        int cnt = 0, ans = 0;
        dfs(root, cnt, arr);
        sort(arr.begin(), arr.end());
        int m = arr.size() - 1;
        for(int i = m; i >= 0; i--) {
            if(arr[i].first == arr[m].first) ans += arr[i].second;
            else break;
        }
        return ans;
    }
};