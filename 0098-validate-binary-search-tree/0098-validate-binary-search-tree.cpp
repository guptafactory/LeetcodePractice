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
    bool checkIfBST(TreeNode* root, long long minValue, long long maxValue) {
        if(root == NULL) return true;
        if(root->val <= minValue || root->val >= maxValue) return false;
        return checkIfBST(root->left, minValue, root->val) && checkIfBST(root->right, root->val, maxValue);
    }
    bool isValidBST(TreeNode* root) {
        return checkIfBST(root, LLONG_MIN, LLONG_MAX);
    }
};