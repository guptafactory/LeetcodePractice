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
    int subTreeBalanced(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int lh = subTreeBalanced(root->left);
    if (lh == -1)
        return -1;
    int rh = subTreeBalanced(root->right);
    if (rh == -1)
        return -1;
    return (abs(lh - rh) > 1) ? -1 : (max(lh, rh) + 1);
}
    bool isBalanced(TreeNode* root) 
    {
        if(subTreeBalanced(root) == -1) return false;
        else return true;
    }
};