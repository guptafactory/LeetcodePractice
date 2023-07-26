/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool pathArray(TreeNode* root, TreeNode* a, vector<TreeNode*>&arr) {
        if(root == NULL) return false;
        arr.push_back(root);
        if(root == a) return true;
        if((root->left && pathArray(root->left, a, arr)) || (root->right && pathArray(root->right, a, arr))) return true;
        arr.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(p == q) return p;
        vector <TreeNode*> pathP, pathQ;
        if(pathArray(root, p, pathP) && pathArray(root, q, pathQ)  == 0) return NULL;
        int i = 0;
        for(i = 0; (i < pathP.size()) && (i < pathQ.size()) ; i++) {
            if(pathP[i] != pathQ[i]) break;
        }
        return pathP[i-1];
    }
};