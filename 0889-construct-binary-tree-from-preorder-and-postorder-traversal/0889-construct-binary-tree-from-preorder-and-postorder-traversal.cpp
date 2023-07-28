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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return constructTree(preorder, 0, n-1, postorder, 0 , n-1);
    }
    TreeNode* constructTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& postorder, int postStart, int postEnd) 
    {
        if(preStart > preEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        if(preStart == preEnd) return root;
        int ind = postStart;
        while(postorder[ind] != preorder[preStart+1]) ind++;
        int remLeft = ind - postStart + 1; 
        root->left = constructTree(preorder, preStart+1, preStart + remLeft, postorder, postStart, ind);
        root->right = constructTree(preorder, preStart + remLeft + 1, preEnd, postorder, ind + 1, postEnd - 1);
        return root;
    }
};