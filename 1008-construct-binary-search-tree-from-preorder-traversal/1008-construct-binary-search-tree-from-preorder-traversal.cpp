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
    int ind = 0;
    TreeNode* buildBST(vector<int> &preorder, int l, int r)
    {
        if(ind >= preorder.size() || preorder[ind] < l || preorder[ind] > r) return NULL;
        TreeNode* root = new TreeNode(preorder[ind++]);
        root->left = buildBST(preorder, l, root->val);
        root->right = buildBST(preorder, root->val, r);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        int l = 0, r = 1001;
        return buildBST(preorder, l, r);
    }
};