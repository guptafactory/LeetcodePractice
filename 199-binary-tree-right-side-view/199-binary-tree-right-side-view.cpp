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
    vector<int> rightSideView(TreeNode* root) {
        vector <int> arr;
        if(root == NULL) return arr;
        queue <TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            int cnt = que.size();
            for(int i = 0; i < cnt; i++) {
                TreeNode* curr = que.front();
                que.pop();
                if(i == cnt-1) arr.push_back(curr->val);
                if(curr->left != NULL) que.push(curr->left);
                if(curr->right != NULL) que.push(curr->right);
            }
        }
        return arr;
    }
};