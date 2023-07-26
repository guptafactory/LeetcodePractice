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
    int pathArray(TreeNode* root, TreeNode* a, vector<TreeNode*>&arr) {
        if(root == NULL) return 0;
        arr.push_back(root);
        if(root == a) return 1;
        if((root->left && pathArray(root->left, a, arr)) || (root->right && pathArray(root->right, a, arr))) return 1;
        arr.pop_back();
        return 0;
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