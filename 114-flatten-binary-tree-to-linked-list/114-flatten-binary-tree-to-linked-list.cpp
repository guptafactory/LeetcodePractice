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
    void storeNodes(TreeNode* root, queue<TreeNode*>&que)
    {
        if(root == NULL) return;
        que.push(root);
        storeNodes(root->left, que);
        storeNodes(root->right, que);
    }
    TreeNode* createList(TreeNode* root, queue<TreeNode*>&que)
    {
        TreeNode* curr = root;
        while(!que.empty())
        {
            curr->right = que.front();
            curr->left = NULL;
            curr = curr->right;
            que.pop();
        }
        curr->right = NULL;
        return root->right;
    }
    void flatten(TreeNode* root) 
    {
        if(root == NULL) return;
        queue<TreeNode*> que;
        storeNodes(root, que);
        root = createList(root, que);
    }
};