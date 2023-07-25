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
public:
    int childSum(TreeNode *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return root->val;
    return (root->val == childSum(root->left) + childSum(root->right));
}
    bool checkTree(TreeNode* root) {
        return childSum(root);
    }
};