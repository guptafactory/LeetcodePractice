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
    void traverse(TreeNode* root, int num, int &sum) {
        num *= 10;
        if (root->left == NULL && root->right == NULL) { sum += num + root->val; return; }
        if (root->left != NULL) traverse(root->left, num + root->val, sum);
        if (root->right != NULL) traverse(root->right, num + root->val, sum);
    }
public:
    int sumNumbers(TreeNode* root) {
        if (root == NULL) return 0;
        int sum = 0, num = 0;
        traverse(root, num, sum);
        return sum;
    }
};