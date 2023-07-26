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
    TreeNode* tree(vector<int>& preorder, vector<int>& inorder, int &preIndex, int startIndex, int endIndex) {
        if(startIndex > endIndex) return NULL;
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        int inIndex = 0;
        for(int i = startIndex; i <= endIndex; i++) 
        {
            if(inorder[i] == (root->val)) { inIndex = i; break; }
        }
        root->left = tree(preorder, inorder, preIndex, startIndex, inIndex-1);
        root->right = tree(preorder, inorder, preIndex, inIndex+1, endIndex);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0, startIndex = 0, endIndex = inorder.size()-1;
        return tree(preorder, inorder, preIndex, startIndex, endIndex);
    }
};