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
    void dfs(TreeNode* root, int &ans, int prev) {
        if(root == NULL) return;
        if(root->val >= prev) {
            ans++;
            prev = max(prev, root->val);
        }
        dfs(root->left, ans, prev);
        dfs(root->right, ans, prev);
    }
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        dfs(root, ans, INT_MIN);
        return ans;
    }
};