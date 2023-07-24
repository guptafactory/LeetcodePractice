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
    vector<int> largestValues(TreeNode* root) {
        queue <TreeNode*> que;
        que.push(root);
        vector <int> ans;
        if(root == NULL) return ans;
        while(!que.empty())
        {
            int n = que.size(), maxm = INT_MIN;
            for(int i = 0; i < n; i++)
            {
                TreeNode* curr = que.front();
                que.pop();
                if(curr!=NULL) maxm = max(maxm, curr->val);
                if(curr->left != NULL) que.push(curr->left);
                if(curr->right != NULL) que.push(curr->right);
            }
            ans.push_back(maxm);
        }
        return ans;
    }
};