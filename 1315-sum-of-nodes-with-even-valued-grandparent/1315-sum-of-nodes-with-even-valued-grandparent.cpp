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
    int sum;
    void dfs(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL)) return;
        if((root->val)%2 == 0 && root->left != NULL && root->left->left != NULL) sum += root->left->left->val;
        if((root->val)%2 == 0 && root->left != NULL && root->left->right != NULL) sum += root->left->right->val;
        if((root->val)%2 == 0 && root->right != NULL && root->right->left != NULL) sum += root->right->left->val;
        if((root->val)%2 == 0 && root->right != NULL && root->right->right != NULL) sum += root->right->right->val;
        dfs(root->left);
        dfs(root->right);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root);
        return sum;
    }
};